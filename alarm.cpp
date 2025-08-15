#include <iostream>
using namespace std;

void alarm_rings(){
    char wakeup,late;
    cout<<"Are you ready to wake up?\n";
    cin>>wakeup;
    if(wakeup=='y'){
        cout<<"Leave bed\n";
    }
    else if(wakeup=='n'){
        cout<<"Are you late?\n";
        cin>>late;
        if(late=='n'){
            cout<<"Snooze the alarm 5mins\n";
            alarm_rings();
        }
    }
    cout<<"Leave bed";
}

int main(){
    char set;
    cout<<"Is Alarm set?\n";
    cin>>set;
    if(set=='y'){
        alarm_rings();
    }
    cout<<"Turn off Alarm\n";
}