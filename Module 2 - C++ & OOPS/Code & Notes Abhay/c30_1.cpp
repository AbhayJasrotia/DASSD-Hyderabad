#include<iostream>
using namespace std;

class Point{
    int a, b;

    public:
    Point(int x, int y);

    void display(){
        cout<<"Points are X = "<< a << " and Y = "<< b<<endl;
    }
    void distance(){
        cout<< b - a << b - a<<endl;
    }
};

Point :: Point(int x, int y){
    a = x;
    b = y;
}

int main(){
    Point now(2, 4);
    now.display();

    Point future(6, 8);
    future.display();
    return 0;
}