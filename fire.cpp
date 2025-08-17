
#include <iostream>
using namespace std;

void handleHotDoor() {
    cout << "Do not open the door\n";
    cout << "Seal all cracks with wet towels\n";
    cout << "Contact the fire department\n";
    cout << "Wave at doors for rescuers\n";
    cout << "Wait for rescue\n";
}

void evacuation() {
    char doorHot, escape, reachedBalcony;

    cout << "Are doors hot or is smoke seeping in? (y/n): ";
    cin >> doorHot;

    if (tolower(doorHot) == 'y') {
        handleHotDoor();
    } else {
        cout << "Go downstairs until you leave the building.\n";
        cout << "Did you escape the building? (y/n): ";
        cin >> escape;

        if (tolower(escape) == 'y') return;

        while (true) {
            cout << "Have you seen the fire? (y/n): ";
            cin >> escape;

            if (tolower(escape) == 'y') {
                cout << "Go upstairs and head to the balcony.\n";
                cout << "Reached the balcony? (y/n): ";
                cin >> reachedBalcony;

                if (tolower(reachedBalcony) == 'y') {
                    cout << "Wait for the rescue.\n";
                    break;
                }
            }
        }
    }
}

void smoke() {
    int option;
    char fireInBuilding;

    cout << "1. You or someone sees fire or smoke\n";
    cout << "2. Smoke detector finds fire\n";
    cout << "Choose an option (1 or 2): ";
    cin >> option;

    if (option == 1) {
        cout << "Is the fire in the building? (y/n): ";
        cin >> fireInBuilding;

        if (tolower(fireInBuilding) == 'n') {
            cout << "Contact the fire department\n";
        } else {
            cout << "Push the alarm trigger\n";
        }
    } else if (option == 2) {
        cout << "Smoke detector triggers alarm\n";
    } else {
        cout << "Invalid option\n";
    }

    cout << "Bring phone, keys, and wallet\n";
    evacuation();
}

int main() {
    smoke();
    return 0;
}
