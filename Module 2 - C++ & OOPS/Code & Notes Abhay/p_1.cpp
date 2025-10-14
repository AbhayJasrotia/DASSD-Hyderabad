#include<iostream>
using namespace std;

class Car{
    public:
        string brand;
        string model;
        int price;

        void input(){
            cout<<"Enter brand"<<endl;
            cin>>brand;
        }

        void display(){
            cout<<"Brand is - "<<brand<<endl;
        }
};

int main(){
    Car c1, c2;
    c1.input();
    c2. input();
    c1.display();
    c2.display();
    return 0;

}