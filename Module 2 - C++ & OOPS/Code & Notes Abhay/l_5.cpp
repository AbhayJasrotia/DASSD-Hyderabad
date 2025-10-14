#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void displayType() {    // virtual for proper override
        cout << "This is a generic vehicle." << endl;
    }
};

class Car : public Vehicle {
public:
    void displayType() override {
        cout << "This is a Car (Land Vehicle)." << endl;
    }
};

class Bike : public Vehicle {
public:
    void displayType() override {
        cout << "This is a Bike (Two-wheeler)." << endl;
    }
};

class Truck : public Vehicle {
public:
    void displayType() override {
        cout << "This is a Truck (Heavy Vehicle)." << endl;
    }
};

int main() {
    Car c1;
    Bike b1;
    Truck t1;

    c1.displayType();
    b1.displayType();
    t1.displayType();
    return 0;
}
