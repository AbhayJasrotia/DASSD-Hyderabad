#include <iostream>
#include <string>
using namespace std;

// ===============================
// Base Class: Employee
// ===============================
class Employee {
private:
    string name;
    int id;
    float baseSalary;

protected:
    float bonus; // only accessible by derived classes

public:
    // Constructor
    Employee(string n, int i, float s) {
        name = n;
        id = i;
        baseSalary = s;
        bonus = 0;
    }

    // Virtual function to calculate bonus (base version)
    virtual void calculateBonus() {
        bonus = 0; // Default: no bonus
    }

    // Virtual function to display employee details
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << baseSalary + bonus << endl;
    }

    // Virtual destructor for safe cleanup
    virtual ~Employee() {
        cout << "Employee object destroyed for ID " << id << endl;
    }

    // Getter for baseSalary (for derived classes)
    float getBaseSalary() {
        return baseSalary;
    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }
};

// ===============================
// Derived Class: Manager
// ===============================
class Manager : public Employee {
public:
    // Constructor
    Manager(string n, int i, float s) : Employee(n, i, s) {}

    // Override calculateBonus() → 40% of base salary
    void calculateBonus() override {
        bonus = 0.4 * getBaseSalary();
    }

    // Override display()
    void display() override {
        cout << "----- Manager Details -----" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getId() << endl;
        cout << "Base Salary: " << getBaseSalary() << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << getBaseSalary() + bonus << endl;
        cout << "---------------------------" << endl;
    }

    ~Manager() {
        cout << "Manager object destroyed for ID " << getId() << endl;
    }
};

// ===============================
// Derived Class: Developer
// ===============================
class Developer : public Employee {
public:
    Developer(string n, int i, float s) : Employee(n, i, s) {}

    // Override calculateBonus() → 25% of base salary
    void calculateBonus() override {
        bonus = 0.25 * getBaseSalary();
    }

    // Override display()
    void display() override {
        cout << "----- Developer Details -----" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getId() << endl;
        cout << "Base Salary: " << getBaseSalary() << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << getBaseSalary() + bonus << endl;
        cout << "-----------------------------" << endl;
    }

    ~Developer() {
        cout << "Developer object destroyed for ID " << getId() << endl;
    }
};

// ===============================
// Main Function
// ===============================
int main() {
    int num;
    cout << "Enter number of employees: ";
    cin >> num;

    // Dynamically create an array of Employee pointers
    Employee** employees = new Employee*[num];

    for (int i = 0; i < num; i++) {
        int choice, id;
        string name;
        float salary;

        cout << "\nEnter details for Employee " << (i + 1) << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Base Salary: ";
        cin >> salary;

        cout << "Select Employee Type (1 = Manager, 2 = Developer): ";
        cin >> choice;

        if (choice == 1) {
            employees[i] = new Manager(name, id, salary);
        } else {
            employees[i] = new Developer(name, id, salary);
        }

        // Calculate bonus
        employees[i]->calculateBonus();
    }

    cout << "\n========== Employee Details ==========\n";

    // Display all employees
    for (int i = 0; i < num; i++) {
        employees[i]->display();
    }

    // Delete all dynamically allocated employees
    for (int i = 0; i < num; i++) {
        delete employees[i];
    }

    // Delete the array itself
    delete[] employees;

    cout << "\nAll employee data cleared safely.\n";

    return 0;
}
