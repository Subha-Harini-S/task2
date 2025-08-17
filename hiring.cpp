#include <iostream>
using namespace std;

void job(){
    cout<<"define job description\n";
    cout<<"Send crew request to HR team\ndetermine Classification\n";
    char hiring;
    cout<<"Regular hiring process\n";
    cin>>hiring;
    if(hiring=='y'){
        cout<<"Post job internally\n";
    }
    else{
        cout<<"Special hiring process\n";
    }
}



void yes(){
    cout<<"Arrange candidate meeting\n Conduct pre-iterview\n Setup interview questions\n Conduct interview\n";
    char ref;
    cout<<"Good reference\n";
    cin>>ref;
    if(ref=='y'){
        cout<<"Select candidate\n Evaluate the pay rate\n Send employment offer\n";
        char offer;
        cout<<"Candidate confirms offer?\n";
        if(ref=='y'){
            cout<<"Hire candidate\n";
        }
    }

}

void no(){
    cout<<"Develop recruitment plan\n Place advertisement\n Collect applications\n";
    char resume;
    cout<<"Is it a qualified resume?\n";
    cin>>resume;
    if(resume=='y'){
        yes();
    }
}


int main(){
    job();
    char ch;
    cout<<"Is the person is suitable candidate\n";
    if(ch=='y'){
        yes();
    }
    else no();
    cout<<"Candidate not hired\n";
}