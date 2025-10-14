#include<iostream>
using namespace std;

class BankAccount{
    private:
        int accNumber;
        int balance;
    
    public:

        void setdata(int a, int b){
            accNumber = a;
            balance = b;
        }

        void desposit(){
            int amount;
            cout<<"Enter the amount: "<<endl;
            cin>>amount;
            balance = balance + amount;
            cout<<"Deposit Success"<<endl;
        }

        void withdraw(){
            int amount;
            cout<<"Enter the amount: "<<endl;
            cin>>amount;
            if(amount > balance){
                cout<<"Nope"<<endl;
            }
            else{
                balance -= amount;
                cout<<"Sucess"<<endl;
            }
        }

        void displayBalance(){
            cout<<accNumber<< " " <<balance<<endl;

        }
};

int main(){
    BankAccount p1;
    p1.setdata(1001, 0);
    p1.desposit();
    p1.withdraw();
    p1.displayBalance();
    return 0;

}