#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
};

vector<User> loadUsers(const string& filename) {
    // Dummy loader for illustration
    return {{"admin", "admin123"}, {"user1", "pass1"}, {"user2", "pass2"}};
}

bool login(const vector<User>& users, const string& uname, const string& pass) {
    for (const auto& user : users) {
        if (user.username == uname && user.password == pass)
            return true;
    }
    return false;
}

void updatePassword(const string& filename, const string& uname, const string& newpass) {
    cout << "Password for " << uname << " updated in " << filename << ".\n";
}

int main() {
    string dbFile = "users.csv";
    vector<User> users = loadUsers(dbFile);

    cout << "Login System\n";
    cout << "Are you Admin (A) or Registered User (R)? : ";
    char choice;
    cin >> choice;

    if (choice == 'A' || choice == 'a') {
        string uname, pass;
        cout << "Enter Admin username: ";
        cin >> uname;
        cout << "Enter Admin password: ";
        cin >> pass;

        if (login(users, uname, pass) && uname == "admin") {
            cout << "Admin login successful!\n";
            cout << "Admin can update all data here...\n";
        } else {
            cout << "Admin login failed.\n";
        }
    } else if (choice == 'R' || choice == 'r') {
        string uname, pass;
        cout << "Enter Username: ";
        cin >> uname;
        cout << "Enter Password: ";
        cin >> pass;

        if (login(users, uname, pass)) {
            cout << "User login successful!\n";
            cout << "Welcome, " << uname << "!\n";
        } else {
            cout << "Invalid credentials!\n";
            cout << "Forgot Password? (Y/N): ";
            char fp;
            cin >> fp;
            if (fp == 'Y' || fp == 'y') {
                string newpass;
                cout << "Enter new password: ";
                cin >> newpass;
                updatePassword(dbFile, uname, newpass);
                cout << "Password updated successfully!\n";
            } else {
                cout << "Returning to main menu...\n";
            }
        }
    } else {
        cout << "Invalid choice!\n";
    }

    cout << "End\n";
    return 0;
}
