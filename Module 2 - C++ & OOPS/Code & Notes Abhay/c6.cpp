#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accNum;
    float balance;

public:
    void setData(int x, int y)
    {
        accNum = x;
        balance = y;
    }
    void deposit();
    void withdraw();
    void display();
};

void BankAccount ::deposit()
{
    int amount;
    cout << "Enter the amount " << endl;
    cin >> amount;
    balance += amount;
}

void BankAccount::withdraw()
{
    int amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount <= balance)
    {
        balance -= amount;
        cout << "Withdrawal successful\n";
    }
    else
    {
        cout << "Insufficient balance!\n";
    }
}

void BankAccount ::display()
{
    cout << "Account Number " << accNum << endl;
    cout << "Balance " << balance << endl;
}

int main()
{
    BankAccount p;
    cout << "<<__Welcome__>>\n"<<endl;;
    int choice;
    int n;
    cout<<"How much acc u want to create: ";
    cin>>n;
    BankAccount* s = new BankAccount[n];
    do
    {
        cout << " 1: Deposit\n 2: Withdraw\n 3: Display\n 4: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            p.deposit();
            break;

        case 2:
            p.withdraw();
            break;

        case 3:
            p.display();
            break;

        case 4:
            cout << "<<Thankyou>>" << endl;
        }
    }while (choice != 4);
    delete []s;
    s = NULL;
    return 0;
}