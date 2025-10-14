#include <iostream>
using namespace std;

class Employee {
public:
    virtual void bonus() = 0;  // pure virtual function
    virtual ~Employee() {
        cout << "Employee Destroyed" << endl;
    }
};

class Manager : public Employee {
private:
    int baseSalary;
    int bonusAmount;
public:
    Manager(int bs, int b) {
        baseSalary = bs;
        bonusAmount = b;
    }

    void bonus() override {
        //float total = baseSalary + bonusAmount;
        cout << "Total salary after bonus added: " << baseSalary + bonusAmount << endl;
        //return total;
    }
};

class Worker : public Employee {
private:
    int baseSalary;
    int hourwork;
    float bonusAmount;

public:
    Worker(int bs, int hw, float b) {
        baseSalary = bs;
        hourwork = hw;
        bonusAmount = b;
    }

    void bonus() override {
        //float total = baseSalary + bonusAmount;
        cout << "Total salary after bonus added acc to hours: " 
        << baseSalary + (hourwork*bonusAmount) << endl;
        //return total;
    }
};

int main() {
    Manager m1(50000, 10000);
    m1.bonus();
    Worker w1(80000, 10, 1000);
    w1.bonus();
    return 0;
}