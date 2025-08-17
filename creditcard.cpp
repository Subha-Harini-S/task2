#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool verifyPayment(bool cardValid, bool fundsAvailable) {
    cout << "Payment verified by card network...\n";
    if (!cardValid) {
        cout << "Card not valid. Payment failed.\n";
        return false;
    }
    if (!fundsAvailable) {
        cout << "Insufficient funds. Payment failed.\n";
        return false;
    }
    cout << "Payment verified by bank.\n";
    return true;
}

void processTransaction(string id, string name, bool accountValid, bool cardValid, bool fundsAvailable) {
    cout << "\nOrder placed by client: " << name << "\n";
    if (accountValid) {
        cout << "Account valid.\n";
        if (verifyPayment(cardValid, fundsAvailable)) {
            cout << "Transaction complete.\n";
            cout << "Card holder receives statement at the end of cycle.\n";
        }
    } else {
        cout << "Account not valid. Transaction failed.\n";
    }
}

int main() {
    ifstream file("dummy.csv");
    if (!file.is_open()) {
        cout << "Error: Could not open dummy.csv\n";
        return 1;
    }

    string line;
    getline(file, line);

    string customerID;
    cout << "Enter Customer ID to process transaction: ";
    cin >> customerID;

    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, acc, card, funds;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, acc, ',');
        getline(ss, card, ',');
        getline(ss, funds, ',');

        if (id == customerID) {
            found = true;
            bool accountValid = (acc == "1");
            bool cardValid = (card == "1");
            bool fundsAvailable = (funds == "1");

            processTransaction(id, name, accountValid, cardValid, fundsAvailable);
            break;
        }
    }

    if (!found) {
        cout << "Customer not found in database.\n";
    }

    file.close();
    cout << "\nEnd.\n";
    return 0;
}
