#include <iostream>
using namespace std;

void medications();
void registration(){
    bool reg;
    bool nurse=true;
    cout<<"Is patient Registered?\n";
    if(!reg){
        cout<<"register the patient details\n";
    }
    else{
        if(!nurse){
            cout<<"Wait for nurse\n";
        }
        else{
            cout<<"Health records are recorded by nurse\n";
        }
    }
}

void doctor(){
    bool doc=true;
    bool scan;
    bool follow_up;
    cout<<"Is Doctor available?\n";
    if(!doc){
        cout<<"Wait for Doctor\n";
    }
    else{
        cout<<"The doctor is assigned to patient.\n";
        cout<<"Do you need scan?";
        cin>>scan;
        if(scan){
            cout<<"Take necessary scans\n";
        }
        cout<<"Do you need followup?\n";
        cin>>follow_up;
        if(follow_up){
            cout<<"Make necessary Arrangements and fix next appointment\n";
        }
    
            medications();
        }
    }

void medications(){
    char med;
    cout<<"Do you need medications?\n";
    cin>>med;
    if(med=='y'){
        cout<<"Give the prescription";
    }
    cout<<"Patient leaves";
}
int main(){
    bool emergency;
    cout<<"patient arrives\n";
    cout<<"Is the patient in emergency situation?\n";
    cin>> emergency;
    if(!emergency){
        registration();
    }
    else{
        doctor();
    }
}