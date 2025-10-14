#include<iostream>
using namespace std;

class Employee{
    private:
        string name;
        int id;
        float baseSalary;

    protected:
        float bonus;
    
    public:
        Employee(string n, int i, float bs){
            name = n;
            id = i;
            baseSalary = bs;
        }

        virtual void calculateBonus(){bonus = 0;};

        virtual ~Employee(){};
};

class Manager : public Employee{
    public:
        Manager(string n, int i, float bs):Employee(n,i,bs){}

        void calculateBonus() override{
            bonus = 0.4 * baseSalary;
        }
};

int main(){
    
    return 0;
}