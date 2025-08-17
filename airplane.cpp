#include <iostream>
using namespace std;

void immigration(){
    cout<<"Immigration\nBoard flight\nFlight departs\nFlight lands";
}

void flight(){
    cout<<"Leave flight\nImmigration\n";
    char permit;
    cout<<"Permit entry to country?\n";
    cin>>permit;
    if(permit=='y'){
        cout<<"Claim baggage\n";
    }
    else cout<<"Send to originate country\n";
}

void process(){
    cout<<"Security screening\n";
    char goods;
    cout<<"Is any metal does the passenger carry?\n";
    cin>>goods;
    if(goods=='m'){
        cout<<"hand search\n";
        cout<<"dangeruous?";
        cin>>goods;
        if(goods=='y'){
            cout<<"Give up dangerous goods\n";
        }
    }
    if(goods=='r'){
        cout<<"Give up articles above permitted limit\n";
    }
        immigration();
        char ch;
        cout<<"Connection\n";
        if(ch=='y'){
            process();
        }
        flight();
}

int main(){
    cout<<"Check in \n baggage drop\n";
    process();

}