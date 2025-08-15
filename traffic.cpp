#include <iostream>
using namespace std;

void traffic_light(){
    char light, car;
    cout<<"Is traffic light present?\n";
    cin>>light;
    string color;
    while(true){
    
    cout<<"Is red light is on?\n";
    cin>>color;
    if(tolower(color=="red")){
        cout<<"Look left\n";
        break;
    }
}
    while(true){
        cout<<"Does any car is approaching?";
        cin>>car;
    if(tolower(car=='n')){
        cout<<"Ready to cross\n";
        break;
    }
}
}
int main(){
    char bridge, tunnel, cross;
    while(true){
        cout<<"Did you found the footbridge\n";
        cin>>bridge;
    if(bridge=='y'){
        
        cout<<"Use the foot bridge\n";
        break;
    }
    cout<<"Did you found the tunnel\n";
    cin>>tunnel;
    if(tunnel=='y'){
        cout<<"Use the tunnel\n";
        break;
    }
    cout<<"Did you found the Crossing\n";
    cin>>cross;
     if(cross=='y'){
        cout<<"Check the traffic light\n";
        break;
    }
    else{
        cout<<"walk away\n";
    }
    }
    traffic_light();
   
    cout<<"Cross the traffic\n";
}