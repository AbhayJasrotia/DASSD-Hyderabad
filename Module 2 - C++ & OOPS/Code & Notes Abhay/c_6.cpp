#include<iostream>
using namespace std;

class Complex{
    private:
        int real;
        int imag;
    public:
        Complex(int r = 0, int i = 0){
            real = r;
            imag = i;
        }
        Complex add(){
            int new_real = real + imag;
            int new_imag = real + imag;
        }

        void display(){
            cout<<real;
            cout<<imag;
        }

};

int main(){
    Complex c1(3, 7);
    Complex c2(4,6);
    c1.display();
    c2.display();
    c1.add();
    c1.display();
    return 0;
}