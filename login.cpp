#include <iostream>
using namespace std;

int main(){
    string auth;
    int cnt=1;
     cout<<"Is the login count is more than 5 or nor?\n";
    
    while(true){
       
           cout<<"Login with username and password\n ";
           cin>>auth;
           if(tolower(auth=="yes")){
            cout<<"Grant access to login\n";
            break;
           }
           else{
            cnt++;
            if(cnt>=5){
            cout<<"Lock the account\n";
           cout<<"Alert user\n";
           break;
            }
           }
        }
    }
