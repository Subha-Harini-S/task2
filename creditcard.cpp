#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool card() {
    while (true) {
        char cardValid;
        cout << "Is Card Valid? (y/n): ";
        cin >> cardValid;
        if (tolower(cardValid) != 'y') {
            cout << "Card Invalid. Transaction Failed.\n";
            continue;
        }

        char funds;
        cout << "Are Funds Available? (y/n): ";
        cin >> funds;
        if (tolower(funds) != 'y') {
            cout << "Insufficient Funds. Transaction Failed.\n";
            continue;
        }

        char bankVerify;
        cout << "Payment Verified by Bank? (y/n): ";
        cin >> bankVerify;
        if (tolower(bankVerify) != 'y') {
            cout << "Bank Rejected Transaction.\n";
            continue;
        }

        break;
    }
    return true;
}

int main() {
    cout << "Order placed By the client \nEnter card number:\n";
    string cardNumber;
    cin >> cardNumber;

    if (!card()) {
        cout << "Transaction Status: Failed\n";
        cout << "Statement will be given.\n";
        ofstream file("creditcard.csv", ios::app);
        if (file.is_open()) {
            file << cardNumber << "," << "Failed" << "\n";
            file.close();
        }
        return 0;
    }

    char accValid;
    while (true) {
        cout << "Is Account Valid? (y/n): ";
        cin >> accValid;
        if (tolower(accValid) != 'y') {
            cout << "Account Invalid. Transaction Failed.\n";
            continue;
        }
        cout << "Account valid\n";
        break;
    }

    cout << "Transaction Status: Success\n";
    cout << "Statement will be given.\n";

    ofstream file("creditcard.csv", ios::app);
    if (file.is_open()) {
        file << cardNumber << "," << "Success" << "\n";
        file.close();
    }

    return 0;
}
