#include<iostream>
#include<climits>
using namespace std;

class Complex{
    private:
        int real;
        int imag;

    public:
        Complex(){
            real = 0;
            imag = 0;
        }

        Complex(int r, int i){
            real = r;
            imag = i;
        }

        Complex operator+(const Complex& other){
            return Complex(real + other.real, imag + other.imag);
        }

        void display(){
            char ch;
            if(ch >= 0){
                ch = '+';
            }
            else{
                ch = '-';
            }
            cout<<real<<ch<<abs(imag)<<"i"<<endl;
        }
};

int main(){
    Complex c1;
    Complex c2(2, 3);
    Complex c3(3, 5);
    Complex c4 = c2 + c3;
    c1.display();
    c2.display();
    c3.display();
    c4.display();
    return 0;
}