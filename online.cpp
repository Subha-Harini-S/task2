#include <iostream>
using namespace std;

void warehouse(){
    cout<<"Whether the items are found in warehouse?\n";
    char ch;
    cin>>ch;
    if(ch=='y'){
        cout<<"Packed with other orders in warehouse\n";
    }
    else if(ch=='n'){
        cout<<"Contact seller to ship good\n";
    }
    cout<<"Seller send good to customer\n";
}

void items(){
    cout<<"Is all items are present?\n";
    string ch;
    cin>>ch;
    if(tolower(ch=="yes")){
        cout<<"Send warehouse goods to customer\n";
        cout<<"Customer collects goods\n";
        cout<<"Seller confirm customer received order\n";
    }
    else{
        warehouse();
    }
}

int main(){
    cout<<"Order placed in online\n";
    items();
}