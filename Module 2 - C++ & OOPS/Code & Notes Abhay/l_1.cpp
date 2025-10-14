// #include <iostream>
// using namespace std;

// // Base class
// class Shape {
// public:
//     // Virtual function for runtime polymorphism
//     virtual void area() {
//         cout << "This is a generic shape." << endl;
//     }
// };

// // Derived class Circle
// class Circle : public Shape {
// private:
//     float radius;
// public:
//     Circle(float r) {
//         radius = r;
//     }

//     void area() override {  // Override base class function
//         cout << "Area of Circle: " << 3.14 * radius * radius << endl;
//     }
// };

// // Derived class Rectangle
// class Rectangle : public Shape {
// private:
//     float length, breadth;
// public:
//     Rectangle(float l, float b) {
//         length = l;
//         breadth = b;
//     }

//     void area() override {
//         cout << "Area of Rectangle: " << length * breadth << endl;
//     }
// };

// int main() {
//     Shape* shapePtr;  // Base class pointer

//     // User input for circle
//     float r;
//     cout << "Enter radius of circle: ";
//     cin >> r;

//     Circle c(r);
//     shapePtr = &c;
//     shapePtr->area();

//     // User input for rectangle
//     float l, b;
//     cout << "Enter length and breadth of rectangle: ";
//     cin >> l >> b;

//     Rectangle rec(l, b);
//     shapePtr = &rec;    // Point base pointer to Rectangle object
//     shapePtr->area();   // Calls Rectangle's area()

//     return 0;
// }


#include<iostream>
using namespace std;

class Shape{
    public:
        virtual void area() = 0;
};

class Circle : public Shape{
    private:
        int radius;
    public:
        Circle(int r){
            radius = r;
        }
        
        void area() override{
            cout<<"Area of cicule is : "<< 3.14*radius*radius<<endl;
        }
};

class Rectangle : public Shape{
    private:
        int length;
        int breadth;

    public:
        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }
        void area() override{
            cout<<"Area of circle is: "<< length*breadth<<endl;
        }
};

int main(){
    Shape *ptr;

    int r;
    cout<<"Enter radius of circle: "<<endl;
    cin>>r;

    Circle c(r);
    ptr = &c;
    ptr->area();
    return 0;
}