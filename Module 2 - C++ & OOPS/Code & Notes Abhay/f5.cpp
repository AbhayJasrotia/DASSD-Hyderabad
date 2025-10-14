#include<iostream>
using namespace std;

inline int add(int a, int b){
    return a + b;
}

inline int sub(int a, int b){
    return a - b;
}

inline int mul(int a, int b){
    return a * b;
}

int main(){
    int num1, num2;
    cout<<"Enter the num1: "<<endl;
    cin>>num1;
    cout<<"Enter the num2: "<<endl;
    cin>>num2;
    cout<<"Addition: "<<add(num1,num2)<<endl;
    cout<<"Addition: "<<sub(num1,num2)<<endl;
    cout<<"Addition: "<<mul(num1,num2)<<endl;
    return 0;
}