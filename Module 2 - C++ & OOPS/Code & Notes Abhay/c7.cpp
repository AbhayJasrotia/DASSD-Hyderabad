#include <iostream>
using namespace std;

class BankAccount {
private:
    int accNum;
    float balance;

public:
    void setData(int x, float y) {
        accNum = x;
        balance = y;
    }
    void deposit(float amount) {
        balance += amount;
        cout << "Deposit successful!" << endl;
    }
    void withdraw(float amount) {
        if(amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    void display() {
        cout << "Account Number: " << accNum << endl;
        cout << "Balance: " << balance << endl;
    }
    int getAccNum() {
        return accNum;
    }
};

int main() {
    int n;
    cout << "How many accounts do you want to create? ";
    cin >> n;
    BankAccount* accounts = new BankAccount[n];
    for(int i=0; i<n; i++){
        int acc;
        float bal;
        cout << "\nEnter account number for account " << i+1 << ": ";
        cin >> acc;
        cout << "Enter initial balance: ";
        cin >> bal;
        accounts[i].setData(acc, bal);
    }
    int choice;
    do {
        cout << "\n1: Deposit\n2: Withdraw\n3: Display\n4: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice >= 1 && choice <= 3){
            int targetAcc;
            cout << "Enter account number to operate on: ";
            cin >> targetAcc;
            int index = -1;
            for(int i=0; i<n; i++){
                if(accounts[i].getAccNum() == targetAcc){
                    index = i;
                    break;
                }
            }
            if(index == -1){
                cout << "Account not found!" << endl;
                continue;
            }
            float amount;
            switch(choice){
                case 1:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[index].deposit(amount);
                    break;

                case 2:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[index].withdraw(amount);
                    break;

                case 3:
                    accounts[index].display();
                    break;
            }
        }
        else if(choice == 4){
            cout << "<<Thank you>>" << endl;
        }
        else{
            cout << "Invalid choice!" << endl;
        }
    } while(choice != 4);
    delete[] accounts;
    accounts = NULL;
    return 0;
}
