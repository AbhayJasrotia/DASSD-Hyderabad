#include<iostream>
using namespace std;

class Abhay{
    int age, networth;

    public:
    Abhay(int x, int y);

    void display(){
        cout<<"Abhay age is "<< age << " and salary is per month "<< networth<<endl;
    }
};

Abhay :: Abhay(int x, int y){
    age = x;
    networth = y;
}

int main(){
    Abhay now(23, 00000);
    now.display();

    Abhay future(28, 120000);
    future.display();

    Abhay future2(35, 200000);
    future2.display();
    return 0;
}