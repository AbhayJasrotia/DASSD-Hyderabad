#include<iostream>
using namespace std;
class Student{
   private:
        string name;
        int id;
        float marks;
    public:
        Student (){}
        Student(string n, int i, float m){
            name = n;
            id = i;
            marks = m;
        }

        void input(){
            cout<<"Name || ID || Marks"<<endl;
            cin>>name>>id>>marks;
        }
    ~Student(){
        cout<<name<<" "<<id<<" "<<marks<<endl;
        cout<<"Student constructor deleted"<<endl;
    }
};
int main(){
    Student s[3];
    for(int i = 0;i<=3;i++){
        cout<<"Enter details: "<<endl;
        s->input();
    }
    // for(int i = 0;i<=3;i++){
    //     cout<<"Displaying: "<<endl;
    //     s->();
    // }
    return 0;
}