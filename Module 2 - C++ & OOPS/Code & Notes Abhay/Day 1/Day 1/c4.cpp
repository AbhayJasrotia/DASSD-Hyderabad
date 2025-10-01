#include <iostream>
using namespace std;

// Function 1: adds two integers
int add(int a, int b) {
    return a + b;
}

// Function 2: adds three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Function 3: adds two doubles
double add(double a, double b) {
    return a + b;
}

int main() {
    cout << add(2, 3) << endl;       // Calls Function 1 → 5
    cout << add(1, 2, 3) << endl;    // Calls Function 2 → 6
    cout << add(2.5, 3.5) << endl;   // Calls Function 3 → 6.0
    return 0;
}
