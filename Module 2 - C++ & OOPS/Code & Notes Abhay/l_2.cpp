#include<iostream>
using namespace std;

class Person{
    public:
        string name;
        int age;
    void setPerson(string n, int a){
        name = n;
        age = a;
    }    
};
class Teacher: public Person{
    public:
        string subject;
        float salary;
    
    void setTeacher(string s, float sa){
        subject = s;
        salary = sa;
    }

    void display(){
        cout<<"Teacher name is "<<name<< " his age is "<<age
        <<" he teaches "<<subject<<" his salary is "<<salary<<endl;
    }
};

int main(){
    Teacher t1;
    string x;
    cout<<"Enter the name: "<<endl;
    cin>>x;
    int y;
    cout<<"Enter age: "<<endl;
    cin>>y;
    string p;
    cout<<"Enter subject"<<endl;
    cin>>p;
    int q;
    cout<<"Enter salary: "<<endl;
    cin>>q;
    t1.setPerson(x , y);
    t1.setTeacher(p, q);
    t1.display();
    return 0;
}