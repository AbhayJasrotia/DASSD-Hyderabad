#include<iostream>
using namespace std;

class Complex{
    private:
        int real;
        int imag;
        friend void addComplex(Complex, Complex);
    
    public:
        Complex(int r, int i){
            real = r;
            imag = i;
        }

        void display(){
            cout<<"Your complex number is "<<real<<" + "<<imag<<"i"<<endl;
        }
};

void addComplex(Complex c1, Complex c2){
    int real_part = c1.real+c2.real;
    int imag_part = c1.imag+c2.imag;

    cout<<"Addition of two complex number is "<<real_part<<" + "
    <<imag_part<<"i"<<endl;
}

int main(){
    int a,b,c,d;
    cout<<"Enter the values for complex 1: "<<endl;
    cin>>a>>b;
    Complex c1(a,b);
    c1.display();

    cout<<"Enter the values for complex 2: "<<endl;
    cin>>c>>d;
    Complex c2(c,d);
    c2.display();
    addComplex(c1,c2);
    return 0;
}