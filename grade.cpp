#include <iostream>
using namespace std;

void score(){
    int mark;
    cout<<"Enter the mark:\n";
    cin>>mark;
    if(mark<=0 && mark>=100){
        cout<<"Invalid mark, Re-enter the mark\n";
        score();
    }
    else{
    if(mark>=80)
            cout<<"Grade : A";
        
    else if(mark>=60)
            cout<<"Grade : B";
            
    else if(mark>=50)
            cout<<"Grade : C";
            
    else
            cout<<"Fail";  
    }
}

int main(){
    string revaluation;
    score();
    while(true){
          cout<<"Is revaluation is applied?\n";
        cin>>revaluation;
        if(tolower(revaluation=="yes"))
        score();
        break;
   
    }
    }
