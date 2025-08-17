#include <iostream>
using namespace std;

void services(){
    cout<<"Enquires\n";
    char ch;
    cin>>ch;
    if(ch=='y'){
        cout<<"Answer question\n";
    }
    else{
        cout<<"Safe issues\n";
        cin>>ch;
        if(ch=='y'){
            cout<<"Redirect to sales support\n";
        }
    }
}

int main(){
    cout<<"Customer found issue\n Customer contact customer services\n";
    services();
}