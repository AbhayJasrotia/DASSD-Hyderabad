#include <iostream>
using namespace std;

class Student {
public:
    string name;
    void setStudent(string n) {
        name = n;
    }
};

class Undergraduate : public Student {
public:
    string stream;
    void setUndergrad(string s) {
        stream = s;
    }
    // void display() {
    //     cout << "Name: " << name << " | Stream: " << stream << endl;
    // }
};

class ScholarshipStudent : public Undergraduate {
public:
    float scholarshipAmount;
    void setScholarship(float amt) {
        scholarshipAmount = amt;
    }
    void display() {
        cout << "Name: " << name
             << " | Stream: " << stream
             << " | Scholarship: " << scholarshipAmount << endl;
    }
};

int main() {
    ScholarshipStudent s1;
    s1.setStudent("Patrick");
    s1.setUndergrad("B.Tech");
    s1.setScholarship(25000);
    s1.display();
    return 0;
}
