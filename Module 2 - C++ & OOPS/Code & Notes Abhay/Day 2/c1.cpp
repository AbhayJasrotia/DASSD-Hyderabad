#include<iostream>
using namespace std;

class dog{
    private:
        int a, b, c;
    public:
        int d, e;
        void setdata(int a1, int b1, int c1);
        void getdata(){
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<c<<endl;
        cout<<d<<endl;
        cout<<e<<endl;
        }
};

void dog :: setdata(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    dog german;
    german.d = 4;
    german.e = 5;
    german.setdata(1, 2, 3);
    german.getdata();
    return 0;
}