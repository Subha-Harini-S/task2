#include <iostream>
using namespace std;

void coffee(bool power){
    int choice;
    cout<<"Select your choice\n";
    cin>> choice;
    bool poweroff;
    switch(choice){
        case 1:
           cout<<"Add choco powder\n";
        case 2:
           cout<<"Add frothed milk\n";
        case 3:
           cout<<"Add hot coffee\n";
           break;
        default:
           cout<<"Choice not found\n";
           break;
    }

cout<<"Do you want to turn off?\n";
cin>>poweroff;
if(poweroff){
    coffee(poweroff);
}
}
int main(){
    bool power= true;
    coffee(power);
}