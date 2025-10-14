#include<iostream>
using namespace std;

class Calculator{
    public:
        void add(int a, int b){
            cout<<"Adding a + b = "<<a+b<<endl;
        }

        void add(float a, float b){
            cout<<"Adding a + b = "<<a+b<<endl;
        }

        void add(int a, int b, int c){
            cout<<"Adding a + b = "<<a+b+c<<endl;
        }
};

int main(){
    Calculator a;
    a.add(3,6);
    a.add(3.5f,1.5f);
    a.add(1,2,3);
    return 0;
}