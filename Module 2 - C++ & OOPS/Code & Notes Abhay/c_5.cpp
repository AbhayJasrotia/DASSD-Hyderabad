#include<iostream>
using namespace std;

class Employee{
    private:
        int id;
        string name;
        float salary;
    public:
        Employee(int i, string n, int s){
            id = i;
            name = n;
            salary = s;
        }

        void display(){
            cout<<"Employee id is:"<<id <<" ||"
            <<"Employee name is : "<<name<<" || and his salary is: "
            <<salary<<endl;
        }
};
// int main(){
//     Employee(1001,"Abhay",54000);
//     Employee.display();
//     return 0;
// }

int main(){
    Employee s1(1001,"Abhay",54000);
    s1.display();
    return 0;
}