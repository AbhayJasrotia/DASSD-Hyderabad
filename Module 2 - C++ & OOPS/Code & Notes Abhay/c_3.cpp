#include <iostream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    void input() {
        cout << "Enter Roll No, Name, and Marks: ";
        cin >> rollNo >> name >> marks;
    }

    void display() {
        cout << "Roll No: " << rollNo 
             << " | Name: " << name 
             << " | Marks: " << marks << endl;
    }
};

int main() {
    int n;
    cin>>n;
    Student*s = new Student[n];
    cout << "--- Enter Details for n Students ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        s[i].input();
    }

    cout << "\n--- Student Details ---" << endl;
    for (int i = 0; i < n; i++) {
        s[i].display();
    }

    return 0;
}
