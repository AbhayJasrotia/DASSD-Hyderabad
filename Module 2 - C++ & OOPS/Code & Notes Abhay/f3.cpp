#include<iostream>
using namespace std;

class Employee{
    public:
    virtual void bonus()=0;
};

class Manager : public Employee{
    private:
        int basepay;
    
    public:
        Manager(){}
        Manager(int bp){
            basepay = bp;
        }
        
        void bonus()override{
            int bonus1;
            cout<<"Total salary after adding bonus: "<<bonus1+basepay<<endl;
        }
};

int main(){
    int bonus1;
    Manager m1;
    cout<<"Enter bonus for manager: "<<endl;
    cin>>bonus1;
    m1.bonus();
    return 0;
}