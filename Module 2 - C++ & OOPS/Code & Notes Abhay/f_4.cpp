#include <iostream>
#include <string>
using namespace std;

// ===============================
// Base Class: Employee
// ===============================
class Employee {
private:
    string name;
    int empID;

protected:
    float salary;

public:
    // Parameterized Constructor
    Employee(string n, int id) {
        name = n;
        empID = id;
        salary = 0;
    }

    // Display basic info
    void displayBasic() {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << empID << endl;
    }

    // Get Salary
    float getSalary() {
        return salary;
    }

    // Get Employee ID (for searching or deleting)
    int getID() {
        return empID;
    }

    // Virtual display (for polymorphism)
    virtual void displayDetails() {
        displayBasic();
        cout << "Salary: " << salary << endl;
    }

    // Virtual destructor
    virtual ~Employee() {
        cout << "Employee (ID " << empID << ") destroyed." << endl;
    }
};

// ===============================
// Derived Class: FullTimeEmployee
// ===============================
class FullTimeEmployee : public Employee {
private:
    float basicPay;
    float bonus;

public:
    // Constructor (calls base constructor)
    FullTimeEmployee(string n, int id, float bPay, float bns)
        : Employee(n, id), basicPay(bPay), bonus(bns) {}

    // Calculate Salary
    void calculateSalary() {
        salary = basicPay + bonus;
    }

    // Display Details
    void displayDetails() override {
        cout << "\n--- Full Time Employee ---" << endl;
        displayBasic();
        cout << "Basic Pay: " << basicPay << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << salary << endl;
    }

    // Destructor
    ~FullTimeEmployee() {
        cout << "FullTimeEmployee object cleaned up." << endl;
    }
};

// ===============================
// Derived Class: PartTimeEmployee
// ===============================
class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    float hourlyRate;

public:
    // Constructor
    PartTimeEmployee(string n, int id, int hours, float rate)
        : Employee(n, id), hoursWorked(hours), hourlyRate(rate) {}

    // Calculate Salary
    void calculateSalary() {
        salary = hoursWorked * hourlyRate;
    }

    // Display Details
    void displayDetails() override {
        cout << "\n--- Part Time Employee ---" << endl;
        displayBasic();
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Total Salary: " << salary << endl;
    }

    // Destructor
    ~PartTimeEmployee() {
        cout << "PartTimeEmployee object cleaned up." << endl;
    }
};

// ===============================
// Main Function
// ===============================
int main() {
    Employee* employees[100]; // array of employee pointers
    int empCount = 0;         // track number of employees
    int choice;

    do {
        cout << "\n========= EMPLOYEE MANAGEMENT MENU =========" << endl;
        cout << "1. Add Full-Time Employee" << endl;
        cout << "2. Add Part-Time Employee" << endl;
        cout << "3. Display All Employees" << endl;
        cout << "4. Search Employee by ID" << endl;
        cout << "5. Delete Employee by ID" << endl;
        cout << "6. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id;
            float basic, bonus;
            cout << "\nEnter Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Basic Pay: ";
            cin >> basic;
            cout << "Enter Bonus: ";
            cin >> bonus;

            FullTimeEmployee* f = new FullTimeEmployee(name, id, basic, bonus);
            f->calculateSalary();
            employees[empCount++] = f;
            cout << "Full-Time Employee added successfully!\n";

        } else if (choice == 2) {
            string name;
            int id, hours;
            float rate;
            cout << "\nEnter Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Hours Worked: ";
            cin >> hours;
            cout << "Enter Hourly Rate: ";
            cin >> rate;

            PartTimeEmployee* p = new PartTimeEmployee(name, id, hours, rate);
            p->calculateSalary();
            employees[empCount++] = p;
            cout << "Part-Time Employee added successfully!\n";

        } else if (choice == 3) {
            cout << "\n===== All Employees =====" << endl;
            if (empCount == 0) {
                cout << "No employees to display." << endl;
            } else {
                for (int i = 0; i < empCount; i++) {
                    employees[i]->displayDetails();
                }
            }

        } else if (choice == 4) {
            int id;
            cout << "\nEnter Employee ID to search: ";
            cin >> id;
            bool found = false;

            for (int i = 0; i < empCount; i++) {
                if (employees[i]->getID() == id) {
                    cout << "Employee Found!" << endl;
                    employees[i]->displayDetails();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Employee with ID " << id << " not found." << endl;
            }

        } else if (choice == 5) {
            int id;
            cout << "\nEnter Employee ID to delete: ";
            cin >> id;
            bool deleted = false;

            for (int i = 0; i < empCount; i++) {
                if (employees[i]->getID() == id) {
                    delete employees[i]; // free memory
                    // Shift remaining employees left
                    for (int j = i; j < empCount - 1; j++) {
                        employees[j] = employees[j + 1];
                    }
                    empCount--;
                    cout << "Employee deleted successfully.\n";
                    deleted = true;
                    break;
                }
            }
            if (!deleted) {
                cout << "Employee with ID " << id << " not found." << endl;
            }

        } else if (choice == 6) {
            cout << "\nExiting Program... Cleaning up memory..." << endl;
            // Delete all remaining employees
            for (int i = 0; i < empCount; i++) {
                delete employees[i];
            }
            cout << "All data cleared safely.\n";

        } else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    cout << "\nThank you for using Employee Management System!" << endl;
    return 0;
}
