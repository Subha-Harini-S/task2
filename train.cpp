#include <iostream>
using namespace std;

void buy_ticket(){
    cout<<"Do you need seat reservation?\n";
    string res,res1;
    cin>>res;
    if(tolower(res=="yes")){
    cout<<"Select seat\n";
    }
    else if(tolower(res=="no")){
    cout<<"Do you want a reservation?\n";
    if(tolower(res1=="yes")){
        cout<<"Select seat\n";
    } 
    else 
    buy_ticket();
    }
}

void collect_ticket(){
    cout<<"Collect tickets from mail ot ticket machine\n";
    string collect;
    cin>>collect;
    if(tolower(collect=="mail")){
        cout<<"Check letter box in 3 days\n";
    }
    else if(tolower(collect=="ticketmachine")){
        cout<<"Collect ticket from ticket machine\n";
    }
    cout<<"Board the train\n";
}

void reservation(){
    cout<<"Have any reservation?\n";
    string reserve;
    cin>>reserve;
    if(tolower(reserve=="yes")){
        cout<<"Look for the assigned seat\n";
    }
    else{
        cout<<"Look for the unassigned seat\n";
    }
    cout<<"Finally the tickets are checked by inspector\n";
}

void discount(){
    cout<<"Discounted ticket\n";
    string dis;
    cin>>dis;
    if(tolower(dis=="yes")){
        cout<<"Show valid documentation\n";
    }
    while(true){
        cout<<"Did you arrive your destination?\n";
        string arrive;
        cin>>arrive;
        if(tolower(arrive=="yes")){
            cout<<"Leave the train\n";
            break;
        }
    }
}

int main(){
    cout<<"Buy train ticket\n";
    buy_ticket();
    collect_ticket();
    reservation();
    discount();
}