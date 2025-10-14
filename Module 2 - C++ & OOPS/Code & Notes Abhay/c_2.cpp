#include<iostream>
using namespace std;

class Rectangle{
    private:
        int lenght;
        int width;

    public:
        void setdata(int l, int w){
            lenght = l;
            width = w;
        }

        void area(){
            cout<<"Area of rectangle is : "<<lenght*width<<endl;
        }

        void perimeter(){
            cout<<"Perimeter of rectangle is : "<<2*(lenght+width)<<endl;
        }
};

int main(){
    Rectangle find;
    int len, wid;
    cout<<"Enter lenght and width: "<<endl;
    cin>>len>>wid;
    find.setdata(len, wid);
    find.area();
    find.perimeter();
    return 0;
}