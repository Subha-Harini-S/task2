#include <iostream>
using namespace std;

void umbrella(){
     int search=0;
     bool umbrella;
     while(search<=5){
        cout<<"search for umbrella\n";
        cout<<"Have you found the umbrella?\n";
        cin>>umbrella;
        if(umbrella){
            cout<<"Found umbrella\n";
            break;
        }
        else
        search++;
     }
     if(search>6)cout<<"Buy new umbrella!\n";
}
int main(){
    bool rain;
    cout<<"Is it raining?\n";
    cin>> rain;
    if(!rain){
        cout<<"Don't bring umbrella";
    }
    else{
        umbrella();
        cout<<"Bring Umbrella";
    }
}