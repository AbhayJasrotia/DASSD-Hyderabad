#include<iostream>
using namespace std;

class Number{
    int a;

    public:
    Number () {}

    Number(int x){
        a = x;
    }
    void display(){
        cout<<"Number is yo: "<< a<<endl;
    }
};

int main(){
    Number m=1, n=2, o=3;
    m.display();
    n.display();
    o.display();
    return 0;
}