#include<iostream>
using namespace std;

class Employee{
    private:
        int id;
        string name;
        float salary;

    public:
        Employee(){}
        Employee(int i, string n, float s){
            id = i;
            name = n;
            salary = s;
        }

        void display(){
            cout<<id<<"|"<<name<<"|"<<salary<<endl;
        }
};

int main(){
    int id;
    string name;
    float salary;
    cout<<"Enter employee id: "<<endl;
    cin>>id;
    cout<<"Enter his name: "<<endl;
    cin>>name;
    cout<<"his salary: "<<endl;
    cin>>salary;
    Employee s1(101, "Abhay", 55000);
    return 0;
}