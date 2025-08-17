#include <iostream>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

struct Student {
    string name;
    string program;
    bool verified = false;
    bool needsVisa = false;
    bool visaApplied = false;
    bool feePaid = false;
    bool wantsAccommodation = false;
    string accommodation;
    string tutor;
    bool hasExtraCredits = false;
    string extraCourse;
};

void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool askYesNo(const string& prompt) {
    while (true) {
        cout << prompt << " (y/n): ";
        char c;
        if (!(cin >> c)) { clearLine(); continue; }
        c = tolower(c);
        if (c == 'y') return true;
        if (c == 'n') return false;
        cout << "Please enter y or n.\n";
    }
}

string askLine(const string& prompt) {
    cout << prompt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    getline(cin, s);
    return s;
}

void registration(Student& s) {
    cout << "\n--- Registration Form ---\n";
    if (s.name.empty()) s.name = askLine("Enter student name: ");
    if (s.program.empty()) s.program = askLine("Enter department: ");
    cout << "Registration submitted to departments.\n";
}

void admissionOffice(Student& s) {
    cout << "\n--- Admission Office ---\n";
    cout << "Reviewing form for " << s.name << " (" << s.program << ")\n";
    do {
        s.verified = askYesNo("Are details verified?");
        if (!s.verified) {
            cout << "Please correct the details.\n";
            if (askYesNo("Edit name?")) s.name = askLine("New name: ");
            if (askYesNo("Edit program?")) s.program = askLine("New program: ");
        }
    } while (!s.verified);
    cout << "Details verified.\n";
}

void visaProcess(Student& s) {
    cout << "\n--- Visa Process ---\n";
    s.needsVisa = askYesNo("Does the student need a visa?");
    if (s.needsVisa) {
        do {
            s.visaApplied = askYesNo("Has the visa been applied?");
            if (!s.visaApplied) cout << "Waiting for visa application...\n";
        } while (!s.visaApplied);
        cout << "Visa application acknowledged.\n";
    } else {
        cout << "No visa required.\n";
    }
}

void tuitionFee(Student& s) {
    cout << "\n--- Tuition Fee ---\n";
    do {
        s.feePaid = askYesNo("Has the fee been paid?");
        if (!s.feePaid) cout << "Waiting for payment...\n";
    } while (!s.feePaid);
    cout << "Payment confirmed.\n";
}

void accommodation(Student& s) {
    cout << "\n--- Accommodation ---\n";
    s.wantsAccommodation = askYesNo("Does the student want accommodation?");
    if (s.wantsAccommodation) {
        s.accommodation = askLine("Assign accommodation (room/hostel): ");
        cout << "Accommodation assigned: " << s.accommodation << "\n";
    } else {
        cout << "No accommodation requested.\n";
    }
}

void personalTutor(Student& s) {
    cout << "\n--- Personal Tutor ---\n";
    if (s.tutor.empty())
        s.tutor = askLine("Assign tutor (enter name): ");
    cout << "Tutor assigned: " << s.tutor << "\n";
}

void extraCourse(Student& s) {
    cout << "\n--- Extra Course ---\n";
    s.hasExtraCredits = askYesNo("Does the student have extra credits?");
    if (s.hasExtraCredits) {
        s.extraCourse = askLine("Enter additional course name: ");
        cout << "Extra course selected: " << s.extraCourse << "\n";
    } else {
        cout << "No extra course selected.\n";
    }
}

void fullyRegistered(const Student& s) {
    cout << "\n--- Registration Summary ---\n";
    cout << "Student: " << s.name << " (" << s.program << ")\n";
    cout << boolalpha;
    cout << "Verified: " << s.verified << "\n";
    cout << "Visa: " << (s.needsVisa ? (s.visaApplied ? "Applied" : "Required (not applied)") : "Not required") << "\n";
    cout << "Fee Paid: " << s.feePaid << "\n";
    cout << "Accommodation: " << (s.wantsAccommodation ? s.accommodation : "Not requested") << "\n";
    cout << "Tutor: " << (s.tutor.empty() ? "Not assigned" : s.tutor) << "\n";
    cout << "Extra Course: " << (s.hasExtraCredits ? s.extraCourse : "None") << "\n";
    cout << "Registration completed.\n";
}

void saveToDatabase(const Student& s) {
    bool writeHeader = false;
    ifstream check("students.csv");
    if (!check.good() || check.peek() == ifstream::traits_type::eof()) {
        writeHeader = true;
    }
    check.close();

    ofstream db("students.csv", ios::app);
    if (!db) {
        cerr << "Error opening database file!\n";
        return;
    }

    if (writeHeader) {
        db << "Name,Department,Verified,Visa,FeePaid,Accommodation,Tutor,ExtraCourse\n";
    }

    db << s.name << ","
       << s.program << ","
       << (s.verified ? "Yes" : "No") << ","
       << (s.needsVisa ? (s.visaApplied ? "Applied" : "Required") : "Not required") << ","
       << (s.feePaid ? "Yes" : "No") << ","
       << (s.wantsAccommodation ? s.accommodation : "Not requested") << ","
       << (s.tutor.empty() ? "Not assigned" : s.tutor) << ","
       << (s.hasExtraCredits ? s.extraCourse : "None") << "\n";

    db.close();
    cout << "Student data saved to students.csv\n";
}

int main() {
    Student s;
    registration(s);
    admissionOffice(s);
    visaProcess(s);
    tuitionFee(s);
    accommodation(s);
    personalTutor(s);
    extraCourse(s);
    fullyRegistered(s);
    saveToDatabase(s);
    return 0;
}
