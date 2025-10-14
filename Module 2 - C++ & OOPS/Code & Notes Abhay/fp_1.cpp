#include<iostream>
using namespace std;

class Employee{
    private:
        string name;
        int empID;
    protected:
        float salary;
    public:
        Employee(string n, int e, float s = 0.0f){
            name = n;
            empID = e;
            salary = s;
        }

        virtual void calaculateSalary()=0;

        void displayBasic(){
            cout<<"Employee name is "<<name<<
            " || his id is "<<empID<<" || and his salary is "<<
            salary<<endl;
        }

        ~Employee(){
            cout<<"Employee is destroyed"<<endl;
        }
};

class FullTime : public Employee{
    private:
        float basicPay;
        int bonus;
    
    public:
        FullTime(string n, int e, float bp, float b) 
            : Employee(n, e), basicPay(bp), bonus(b) {}

        void calaculateSalary(){
            salary = basicPay + bonus;
        }
};

class PartTime : public Employee{
    public:
        int hoursWorked;
        int hourlyRate;

        PartTime(string n, int e,int hw, int hr)
            :Employee(n,e), hoursWorked(hw), hourlyRate(hr){}

        void calaculateSalary(){
            salary = hoursWorked*hourlyRate;
        }
};

int main(){
    Employee* e1 = new FullTime("John", 1001, 50000, 5000);
    Employee* e2 = new PartTime("Alice", 1002, 40, 500);
    e1->calaculateSalary();
    e2->calaculateSalary();

    e1->displayBasic();
    e2->displayBasic();

    delete e1;
    delete e2;
    return 0;
}