#include <bits/stdc++.h>
using namespace std;
class Employee
{
private:
    string name;
    int id;

protected:
    float salary;

public:
    Employee(string name, int id)
    {
        this->name = name;
        this->id = id;
        this->salary = 0;
    }
    virtual void display()
    {
        cout << "Name of the employee is " << name << endl;
        cout << "Id of the employee is " << id << endl;
    }
    float getsalary()
    {
        return salary;
    }
    int getId()
    {
        return id;
    }
   virtual ~Employee()
    {
        cout << "Employee destuctor called" << endl;
    }
};
class FullTimeEmployee : public Employee
{
private:
    float basic_pay;
    float bonus;

public:
    FullTimeEmployee(string name, int id, float bp, float bo) : Employee(name, id)
    {
        basic_pay = bp;
        bonus = bo;
    }

    void calculateSalary()
    {
        this->salary = basic_pay + bonus;
    }
    void display()
    {
        Employee::display();
        cout << "Total salary of the employee is " << this->getsalary() << endl;
    }

    ~FullTimeEmployee()
    {
        cout << "Full Time Employee Object Destroyed" << endl;
    }
};
class PartTimeEmployee : public Employee
{
private:
    int hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(string name, int id, int hw, float hr) : Employee(name, id)
    {
        hoursWorked = hw;
        hourlyRate = hr;
    }
    void calculateSalary()
    {
        this->salary = hoursWorked * hourlyRate;
    }
    void display()
    {
        Employee::display();
        cout << "Total salary of the employee is " << this->getsalary() << endl;
    }
    ~PartTimeEmployee()
    {
        cout << "PartTimeEmployee Object Destroyed" << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the total number of employess" << endl;
    cin >> n;
    Employee **arr = new Employee *[n];
    int choice;
    int i = 0;
    do
    {
        cout << "1-Add Full Time Employees\n2-Add Part-Time Employee\n3-Display All Employees\n4-Search Employee by id\n5-Delete Employee by id\n6-Exit" << endl;
        cout << "Enter choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int id;
            float basic_pay, bonus;
            cout << "Enter name of the employee" << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Enter id of the employee is " << endl;
            cin >> id;
            cout << "Enter basix_pay  & bonus" << endl;
            cin >> basic_pay >> bonus;

            arr[i] = new FullTimeEmployee(name, id, basic_pay, bonus);
            ((FullTimeEmployee *)arr[i])->calculateSalary();
            i++;
            break;
        }
        case 2:
        {
            string name;
            int id;
            float hw, hr;
            cout << "Enter name of the employee" << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Enter id of the employee is " << endl;
            cin >> id;
            cout << "Enter hourly rate & hoursworked" << endl;
            cin >> hw >> hr;

            arr[i] = new PartTimeEmployee(name, id, hw, hr);
            ((PartTimeEmployee *)arr[i])->calculateSalary();
            i++;
            break;
        }

        case 3:
            for (int j = 0; j < i; j++)
            {
                cout << endl;
                arr[j]->display();
            }
            cout << endl;
            break;

        case 4:
            int id;
            cout << "Enter id of the employee to be searched" << endl;
            cin >> id;
            for (int j = 0; j < n; j++)
            {
                if (arr[j]->getId() == id)
                {
                    cout << "Employee has been searched" << endl;
                    arr[j]->display();

                    break;
                }
            }

            break;

        case 5:
            int id_;
            cout << "Enter id of the employee to be deleted" << endl;
            cin >> id_;
            for (int j = 0; j < n; j++)
            {
                if (arr[j]->getId() == id)
                {
                    delete arr[j];
                    cout << "Employee with id is deleted successfully" << endl;

                    for (int k = j; k < i-1; k++)
                    {
                        arr[k] = arr[k + 1];
                    }
                    i--;
                    break;
                }
            }
            break;

        case 6:
            cout << "Exiting..." << endl;

        default:
            cout << "Enter Correct Choice" << endl;
        }

    } while (choice != 6);

    for (int j = 0; j < i; j++)
    {
        delete arr[j];
    }

    delete[] arr;

    return 0;
}