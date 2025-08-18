#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string database = "car_rental.csv";

void forgotPassword() {
    cout << "\nEnter username: ";
    string username;
    cin >> username;

    ifstream fin(database);
    ofstream temp("temp.csv");
    string line;
    bool found = false;

    while (getline(fin, line)) {
        size_t pos = line.find(",");
        string dbUser = line.substr(0, pos);
        string dbPass = line.substr(pos + 1);

        if (dbUser == username) {
            found = true;
            string newPass;
            cout << "User found. Enter new password: ";
            cin >> newPass;
            temp << dbUser << "," << newPass << "\n";
        } else {
            temp << line << "\n";
        }
    }

    fin.close();
    temp.close();
    remove(database.c_str());
    rename("temp.csv", database.c_str());

    if (found)
        cout << "Password reset successful!\n";
    else
        cout << "Username not found!\n";
}

void registeredUser() {
    cout << "\nAre you a registered user? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        ifstream fin(database);
        string line;
        bool found = false;

        while (getline(fin, line)) {
            size_t pos = line.find(",");
            string dbUser = line.substr(0, pos);
            string dbPass = line.substr(pos + 1);
            if (dbUser == username && dbPass == password) {
                found = true;
                break;
            }
        }

        fin.close();

        if (found) {
            cout << "Login successful!\n" "Look for desired vehicle\n" "Make payment\n";
        } else {
            cout << "Invalid login!\n";
            cout << "Forgot password? (y/n): ";
            char fp;
            cin >> fp;
            if (fp == 'y')
                forgotPassword();
        }

    } else {
        string username, password;
        cout << "Enter new username: ";
        cin >> username;
        cout << "Enter new password: ";
        cin >> password;
        ofstream fout(database, ios::app);
        fout << username << "," << password << "\n";
        fout.close();
        cout << "Registration successful!\n";
    }
}

void adminLogin() {
    cout << "\nAre you admin? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
        string user, pass;
        cout << "Admin Username: ";
        cin >> user;
        cout << "Admin Password: ";
        cin >> pass;

        if (user == "admin" && pass == "admin123") {
            cout << "Admin login successful!\n1. Update car library\n2. Answer customer queries\n""3. Logout\n";
        } else {
            cout << "Invalid admin credentials!\n";
        }
    } else {
        registeredUser();
    }
}

int main() {
    cout << "CAR RENTAL SYSTEM\n";
    adminLogin();
}
