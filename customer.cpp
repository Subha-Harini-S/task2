#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
 
void logErrorToCSV(const string &description) {
    ofstream file("error.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening error.csv" << endl;
        return;
    }
 
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
 
    file << "Technical Error," << description << "," << dt << "\n";
    file.close();
}
 
void feedback(){
     cout << "feedback(0/1)" << endl;
     bool feedback;
     cin >> feedback;
     if(feedback){
       cout << "Take survey" << endl;
       exit(0);
     }
     else{
        cout << "End" << endl;
     }
     
}
 
void errorReport(){
   cout << "Error analysis" << endl;
   cout << "Solve the issue?(y/n)" << endl;
    cout << "Is the issue fixed(y/n)" << endl;
    char isfixed;
    cin >> isfixed;
    if(tolower(isfixed)=='y'){
        return;
    }
    else{
         logErrorToCSV("Issue not resolved");
        errorReport();
    }
   }
 
 
 
 
void newissue(){
    while(true){
            cout << "Is there is any new issue(y/n)" << endl;
            char isnew;
            cin >> isnew;
            if(tolower(isnew)=='y'){
                cout << "Test the issue" << endl;
                return;
            }
            else{
                cout << "Resolve the issue" << endl;
                return;
            }
}
}
 
void issue(){
     char issuesales;
        cout << "Is there is any issue in sales?(y/n)" << endl;
        cin >> issuesales;
        if(tolower(issuesales)=='y'){
            cout << "Redirect to sales support" << endl;
        }
        else{
            cout << "Is there is any technical issue?(y/n)" << endl;
            char istechissue;
            cin >> istechissue;
            if(tolower(istechissue)=='y'){
               cout << "Contact technical team" << endl;
            }
            else
            newissue();
        }
            cout << "Fixed the issue" << endl;
          
}
 
 
void serviceissues(){
    cout << "Enquiry(y/n)" << endl;
    char enq;
    cin >> enq;
    if(tolower(enq)=='y'){
        cout << "Answer the question" << endl;
        // feedback();
    }
    while(true){
    char simulation;
                cout << "Simulate the issue(y/n)" << endl;
                cin >> simulation;
                if(tolower(simulation)=='y'){
                    errorReport();
                    break;
                }
                else{
                    cout << "Contact customer for information" << endl;
                }
            }
            cout << "Confirm issue fixed with customer" << endl;
            feedback();
 
    else{
        issue();
    }
            
        }
 
 
int main(){
    cout << "Customer has reported an issue" << endl;
    cout << "Customer contacted customer service department" << endl;
    serviceissues();
    cout << "Confirm issue fixed with customer" << endl;
    //feedback();
    // while(true){
    // char simulation;
    //             cout << "Simulate the issue(y/n)" << endl;
    //             cin >> simulation;
    //             if(tolower(simulation)=='y'){
    //                 errorReport();
    //                 break;
    //             }
    //             else{
    //                 cout << "Contact customer for information" << endl;
    //             }
    //         }
    //         cout << "Confirm issue fixed with customer" << endl;
    //         feedback();
 
 
}