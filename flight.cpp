#include <iostream>
using namespace std;
#include <chrono>
#include <thread>
void boarding(){
    cout<<"Start priority boarding\n";
    string first,second;
    cout<<"Do you have First Class ticket\n";
    cin>>first;
    if(first=="yes"){
        cout<<"Board plane\n";
    }
    else if(first=="no"){
        cout<<"Do you have Second Class ticket\n";
        cin>>second;
        if(second=="yes"){
        cout<<"All passengers board plane\n";
        }  
    else if(second=="no"){
        boarding();
    }  
}
}

void aboard(){
    cout<<"Announcements are made\nGate closes in 5 minutes\n";
    this_thread::sleep_for(chrono::seconds(5));
    cout<<"Close the gate\n";
}

int main(){
    cout<<"Plane arrived at the gate\n";
    boarding();
    cout<<"Reach 5 minutes before the gate closes\n";
    aboard();
}