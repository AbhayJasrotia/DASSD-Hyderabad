#include<iostream>
using namespace std;

class BankAccount{
    private:
        int accountNumber;
        float balance;

    public:
        void setdata(int ac, int ba){
            accountNumber = ac;
            balance = ba;
        }

        void deposit(){
            double amount;
            cout<<"Enter amount to bank: "<<endl;
            cin>>amount;
            balance = balance + amount;
        }

        void withdraw(){
            double amount;
            cout<<"Enter amount to withdraw: "<<endl;
            cin>>amount;
            if(amount>balance){
                cout<<"Chutiya!! bakchodi ni"<<endl;
            }
            else{
                balance = balance - amount;
                cout<<"Done pasa withdrawn"<<endl;
            }
        }

        void displayBalance(){
            cout<<balance;
        }
};

int main(){
    BankAccount a1;
    a1.setdata(1001, 0);
    a1.deposit();
    a1.withdraw();
    a1.displayBalance();
    return 0;
}