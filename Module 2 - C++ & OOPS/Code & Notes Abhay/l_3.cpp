#include <iostream>
using namespace std;

// Abstract base class
class Vehicle {
public:
    // Pure virtual function
    virtual void displayInfo() = 0;

    // Virtual destructor (good practice)
    virtual ~Vehicle() {
        cout << "Vehicle object destroyed" << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
private:
    string brand;
    string model;
    float price;

public:
    Car(string b, string m, float p) {
        brand = b;
        model = m;
        price = p;
    }

    void displayInfo() override {
        cout << "\n--- Car Details ---" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: Rs." << price << endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
private:
    string brand;
    string model;
    float price;

public:
    Bike(string b, string m, float p) {
        brand = b;
        model = m;
        price = p;
    }

    void displayInfo() override {
        cout << "\n--- Bike Details ---" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: Rs." << price << endl;
    }
};

int main() {
    Vehicle* vptr;  // Base class pointer

    // --- Input for Car ---
    string carBrand, carModel;
    float carPrice;
    cout << "Enter Car Brand: ";
    cin >> carBrand;
    cout << "Enter Car Model: ";
    cin >> carModel;
    cout << "Enter Car Price: ";
    cin >> carPrice;

    Car c(carBrand, carModel, carPrice);
    vptr = &c;          // Base pointer points to Car
    vptr->displayInfo(); // Calls Car's displayInfo()

    // --- Input for Bike ---
    string bikeBrand, bikeModel;
    float bikePrice;
    cout << "\nEnter Bike Brand: ";
    cin >> bikeBrand;
    cout << "Enter Bike Model: ";
    cin >> bikeModel;
    cout << "Enter Bike Price: ";
    cin >> bikePrice;

    Bike b(bikeBrand, bikeModel, bikePrice);
    vptr = &b;          // Base pointer points to Bike
    vptr->displayInfo(); // Calls Bike's displayInfo()

    return 0;
}
