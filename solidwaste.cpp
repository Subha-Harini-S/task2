#include <iostream>
using namespace std;

void reusable(){
    cout<<"Is the waste is reusable?\n";
    char ch;
    cin>>ch;
    if(tolower(ch=='y')){
        cout<<"Reuse the waste\n";
    }
    else {
        cout<<"Is the waste is recyclable?\n";
        char c;
        cin>>c;
        if(tolower(c=='y')){
            cout<<"Recycle the waste\n";
        }
        else if(tolower(c=='n')){
            cout<<"Landfill\n";
        }
    }
}

void organic_waste(){
    cout<<"Is it a organic waste?\n";
    string waste,energy;
    cin>>waste;
    if(tolower(waste=="yes")){
        cout<<"Does high energy is emitted?\n";
        cin>>energy;
        if(energy=="yes"){
            cout<<"Used as Bio-fuel\n";
        }
        else if(energy=="no"){
            cout<<"Used as organic fertilizer\n";
        }
    }
    else {
            reusable();
        }
}

int main(){
    cout<<"Get Solid waste\n";
    organic_waste();
}