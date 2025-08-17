#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
using namespace std;

void logErrorToCSV(const string& errorType, const string& description) {
    ofstream file("error_database.csv", ios::app);
    if (!file) {
        cerr << "Error opening error_database.csv" << endl;
        return;
    }

    time_t now = time(0);
    char* dt = ctime(&now);
    if (dt != nullptr && strlen(dt) > 0) {
        dt[strlen(dt) - 1] = '\0';
    }

    file << errorType << "," << description << "," << dt << "\n";
    file.close();
}

void answerQuestion() {
    cout << "Customer enquiry answered successfully.\n";
}

void redirectToSalesSupport() {
    cout << "Redirecting to sales support...\n";
}

bool contactTechnicalTeam() {
    cout << "Technical team contacted.\n";
    return true;
}

bool testIssue() {
    cout << "Testing issue...\n";
    return false;
}

void contactCustomerForInfo() {
    cout << "Contacting customer for more information...\n";
}

void confirmIssueFixed() {
    cout << "Issue confirmed fixed with customer.\n";
}

void getFeedback() {
    cout << "Feedback received.\n";
}

void survey() {
    cout << "Survey completed.\n";
}

void errorReport() {
    cout << "Error report generated.\n";
    logErrorToCSV("Technical Error", "Unresolved issue during testing");
}

void errorAnalysis() {
    cout << "Error analysis completed.\n";
}

bool solveIssue() {
    cout << "Attempting to solve issue...\n";
    return true;
}

int main() {
    cout << "Customer found issue.\n";
    cout << "Customer contacted customer service.\n";

    int issueType;
    cout << "Enter issue type (1-Enquiry, 2-Sales, 3-Technical, 4-New Issue): ";
    cin >> issueType;

    switch (issueType) {
        case 1:
            answerQuestion();
            break;
        case 2:
            redirectToSalesSupport();
            break;
        case 3:
            if (contactTechnicalTeam()) {
                confirmIssueFixed();
                getFeedback();
            }
            break;
        case 4:
            if (testIssue()) {
                confirmIssueFixed();
            } else {
                contactCustomerForInfo();
                errorReport();
                errorAnalysis();
                if (solveIssue()) {
                    confirmIssueFixed();
                    getFeedback();
                    survey();
                }
            }
            break;
        default:
            cout << "Invalid input.\n";
    }

    cout << "Process completed.\n";
    return 0;
}

