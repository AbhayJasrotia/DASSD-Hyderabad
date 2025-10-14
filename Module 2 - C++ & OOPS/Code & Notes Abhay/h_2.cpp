#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // Display function
    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
    
    // 🔥 OPERATOR OVERLOADING EXAMPLES 🔥
    
    // 1. Overloading + operator
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
    
    // 2. Overloading - operator
    Point operator-(const Point& other) {
        return Point(x - other.x, y - other.y);
    }
    
    // 3. Overloading == operator
    bool operator==(const Point& other) {
        return (x == other.x && y == other.y);
    }
    
    // 4. Overloading != operator
    bool operator!=(const Point& other) {
        return !(*this == other);
    }
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);
    
    cout << "Point 1: ";
    p1.display();
    
    cout << "Point 2: ";
    p2.display();
    
    // Using overloaded operators
    Point p3 = p1 + p2;  // Calls operator+
    cout << "p1 + p2 = ";
    p3.display();
    
    Point p4 = p1 - p2;  // Calls operator-
    cout << "p1 - p2 = ";
    p4.display();
    
    // Using comparison operators
    if (p1 == p2) {
        cout << "p1 and p2 are equal" << endl;
    } else {
        cout << "p1 and p2 are not equal" << endl;
    }
    
    return 0;
}