#include <iostream>
using namespace std;

class Device {
public:
    virtual void start() = 0;   // pure virtual function
};

class Phone : public Device {
public:
    void start() override {
        cout << "Phone is starting..." << endl;
    }
};

class Laptop : public Device {
public:
    void start() override {
        cout << "Laptop is booting..." << endl;
    }
};

int main() {
    Device* d1 = new Phone();
    Device* d2 = new Laptop();

    d1->start();   // base pointer calls derived method
    d2->start();

    delete d1;
    delete d2;
    return 0;
}
