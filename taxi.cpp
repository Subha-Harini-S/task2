#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Order {
    int id;
    string name;
    int pickupTime;
    string location;
};

struct Taxi {
    int id;
    bool available;
    int distance;
};

bool processOrder(Order o, Taxi &t) {
    if (o.pickupTime > 30) {
        cout << "Pickup time > 30 mins. Wait 1 minute...\n";
        return false;
    }
    if (!t.available) {
        cout << "No taxis available. Wait 1 minute...\n";
        return false;
    }
    if (t.distance > 10) {
        cout << "Taxi too far (>10 km). Wait 1 minute...\n";
        return false;
    }

    cout << "Taxi " << t.id << " assigned to " << o.name << "!\n";
    return true;
}

void taxiRide(Order o, Taxi t) {
    cout << "Passenger " << o.name << " assigned to driver (Taxi " << t.id << ")\n";
    cout << "Taxi ride started from " << o.location << "\n";

    ofstream history("orderHistory.csv", ios::app);
    history << o.id << "," << o.name << "," << o.location << ",Taxi" << t.id << ",Completed\n";
    history.close();

    cout << "Ride complete. Added to order history.\n";
}

Order getOrder(string orderID) {
    ifstream file("orders.csv");
    string line;
    getline(file, line);

    Order o = {0, "", 0, ""};
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, time, loc;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, time, ',');
        getline(ss, loc, ',');

        if (id == orderID) {
            o.id = stoi(id);
            o.name = name;
            o.pickupTime = stoi(time);
            o.location = loc;
            break;
        }
    }
    file.close();
    return o;
}

Taxi findTaxi() {
    ifstream file("taxis.csv");
    string line;
    getline(file, line);

    Taxi t = {0, false, 0};
    while (getline(file, line)) {
        stringstream ss(line);
        string id, available, dist;
        getline(ss, id, ',');
        getline(ss, available, ',');
        getline(ss, dist, ',');

        int avail = stoi(available);
        int d = stoi(dist);
        if (avail == 1) {
            t.id = stoi(id);
            t.available = true;
            t.distance = d;
            break;
        }
    }
    file.close();
    return t;
}

int main() {
    cout << "Taxi Booking\n";

    string orderID;
    cout << "Enter Order ID to process: ";
    cin >> orderID;

    Order o = getOrder(orderID);
    if (o.id == 0) {
        cout << "Order not found in DB.\n";
        return 0;
    }
    cout << "Incoming order from " << o.name << " at " << o.location << "\n";

    Taxi t = findTaxi();
    if (t.id == 0) {
        cout << "No taxis found in DB.\n";
        return 0;
    }

    if (processOrder(o, t)) {
        taxiRide(o, t);
    } else {
        cout << "Order could not be processed.\n";
    }

    cout << "=== End ===\n";
    return 0;
}
