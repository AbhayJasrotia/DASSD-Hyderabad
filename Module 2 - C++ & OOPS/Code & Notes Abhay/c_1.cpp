#include<iostream>
using namespace std;

class Car{
        string name;
        int speed;
    public:
    void setdata(string n , int s){
        name = n;
        speed = s;
    }
    void display(){
        cout<<"Entered car name is "<<name
        <<" and it's speed is "<<speed<<"Km/h"<<endl;
    }
};

int main(){
    Car one;
    string carname;
    int carspeed;
    cout<<"Enter the name of Car 1: "<<endl;
    cin>>carname;
    cout<<"Enter the speed of Car 1: "<<endl;
    cin>>carspeed;
    one.setdata(carname, carspeed);
    Car two;
    string carname1;
    int carspeed1;
    cout<<"Enter the name of Car 2: "<<endl;
    cin>>carname1;
    cout<<"Enter the speed of Car 2: "<<endl;
    cin>>carspeed1;
    two.setdata(carname1, carspeed1);
    one.display();
    two.display();
    return 0;
}