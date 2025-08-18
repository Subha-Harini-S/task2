#include<iostream>
#include<fstream>
using namespace std;
 
string database="student.csv";
fstream fout;
int age;
string name,place,gender;
 
void Registration();
void Visa();
void TuitionFees();
void Accommodation();
void PersonalTutor();
 
void PersonalTutor() {
    cout<<"Assigning a personal tutor for the student\n";
    string credit;
    cout<<"Does the student have extra credits? (yes/no): ";
    cin>>credit;
    if(credit == "yes") {
        cout<<"Choose the extra credit courses.\n";
    } else {
        cout<<"No extra credits assigned.\n";
    }
    cout<<"Student Admission Process Completed.\n";
}
 
void Accommodation() {
    string need;
    cout<<"Do you need accommodation? (yes/no): \n";
    cin>>need;
    if(need=="yes") {
        cout<<"Accommodation assigned successfully.\n";
    } else {
        cout<<"No accommodation required.\n";
    }
    PersonalTutor();
}
 
void TuitionFees() {
    while (true) {
        string fee;
        cout<<"Have you paid the tuition fees? (yes/no): ";
        cin>>fee;
        if(fee == "yes") {
            cout<<"Tuition fees paid successfully.\n";
            Accommodation();
            break;
        } else {
            cout<<"Please pay the tuition fees to continue.\n";
        }
    }
}
 
void Visa() {
    string need,applied;
    cout<<"Do you need a visa? (yes/no): \n";
    cin>>need;
    if(need == "yes") {
        cout<<"Informing student about visa requirements.\n";
        while(true) {
            cout<<"Have you applied for the visa? (yes/no): ";
            cin>>applied;
            if(applied == "yes") {
                cout<<"Visa application is in process.\n";
                TuitionFees();
                break;
            } else {
                cout<<"Please apply for the visa.\n";
            }
        }
    } else {
        TuitionFees();
    }
}
 
void Registration() {
    cout<<"\nRegistration details\n";
    cout<<"\nEnter Student Name: ";
    cin>>name;
    cout<<"\nEnter Age: ";
    cin>>age;
    cout<<"\nEnter Place: ";
    cin>>place;
    cout<<"\nEnter Gender: ";
    cin>>gender;
    fout.open(database, ios::out | ios::app);
    fout<<name<<","<<age<<","<<place<<","<<gender<<"\n";
    fout.close();
    cout<<"Data sent to correspondent successfully.\n";
    Visa();
}
 
int main() {
    cout<<"Complete registration form\n";
    Registration();
    cout<<"Student fully registered\n";
}
 