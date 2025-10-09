#include <bits/stdc++.h>
using namespace std;
class Employee
{
private:
    string name;
    int id;

protected:
    float base_salary;
    float bonus;

public:
    Employee(string name, int id, float bs)
    {
        this->name = name;
        this->id = id;
        this->base_salary = bs;
    }

    virtual void calculatebonus()
    {
        this->bonus = 0;
    }

    virtual void display()
    {
        cout << "Name of the employee is " << name << endl;
        cout << "Id of the employee is " << id << endl;
        cout << "Base salary of the employee is " << base_salary << endl;
        cout << "Total salary is " << base_salary + bonus << endl;
    }

    virtual ~Employee()
    {
        cout << "Employee Object Destroyed" << endl;
    }
};
class Manager : public Employee
{
public:
    Manager(string name, int id, float base_salary) : Employee(name, id, base_salary) {}

    void calculatebonus()
    {
        this->bonus = 0.4f * base_salary;
    }

    void display()
    {
        cout << "\n[Manager details]\n";
        Employee::display();
    }
};
class Developer : public Employee
{
public:
    Developer(string name, int id, float base_salary) : Employee(name, id, base_salary) {}

    void calculatebonus()
    {
        this->bonus = 0.25 * base_salary;
    }

    void display()
    {
        cout << "\n[Developer details]\n";
        Employee::display();
    }
};
int main()
{
    int n;
    cout << "Enter the total number of employess" << endl;
    cin >> n;

    Employee **arr = new Employee *[n];
    for (int i = 0; i < n; i++)
    {
        int type;
        string name;
        int id;
        float base_salary;
        cout << "Enter details for employee " << i + 1 << endl;
        cout << "Enter name" << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter id" << endl;
        cin >> id;
        cout << "Enter base salary of an employee" << endl;
        cin >> base_salary;

        cout << "Enter Type (1-Manager,2-Developer)" << endl;
        cin >> type;

        if (type == 1)
            arr[i] = new Manager(name, id, base_salary);
        else if (type == 2)
            arr[i] = new Developer(name, id, base_salary);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i]->calculatebonus();
        arr[i]->display();
    }

    for (int i = 0; i < n; i++)
        delete arr[i];

    delete[] arr;

    return 0;
}