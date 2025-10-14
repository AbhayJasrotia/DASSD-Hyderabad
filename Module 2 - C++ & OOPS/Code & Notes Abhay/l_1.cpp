#include<iostream>
using namespace std;

class Employee{
    private:
        float salary;
    public:
        void setSalary(float s){
            salary = s;
        }

        float getSalary(){
            return salary;
        }
};

int main(){
    Employee Abhay;
    float userSalary;
    cout<<"Enter salary: ";
    cin>>userSalary;
    Abhay.setSalary(userSalary);
    cout<<Abhay.getSalary();
    return 0;
}