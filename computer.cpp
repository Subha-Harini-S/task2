#include<iostream>
using namespace std;
 
 
int main(){
    while(true){
    bool on;
    cout << "Is computer is on?" << endl;
    cin >> on;
    if(on){
        char err;
        cout << "Is there is any error found on the computer?(y/n)" << endl;
        cin >> err;
        if(err=='y'){
            cout << "Perform diagnosis" << endl;
        }
        else{
            cout << "Computer is in good condition" << endl;
            break;
        }
    }
    else{
        bool power;
        cout << "Is the powerlight on or not?" << endl;
        cin >> power;
        if(power){
            cout << "Find a computer specialist" << endl;
            break;
        }
        else{
            char ch;
            cout << "Is power plugged to the wall?" << endl;
            cin >> ch;
            if(tolower(ch)=='y'){
                cout << "Find a computer specialist" << endl;
                break;
            }
            else{
                cout << "Plug power to the wall" << endl;
            }
        }
    }
}
 
}