#include<iostream>
#include<string>
using namespace std;

class Student{

    private:
    string name;
    int id;
    float marks;

    public:
    void setData(string x, int y, float z){
        name = x;
        id = y;
        marks = z;
    }
    void display();    
};

void Student :: display(){
    cout<<name<<endl;
    cout<<id<<endl;
    cout<<marks<<endl;
}

int main(){
    int n;
    cout<<"Enter total students: "<<endl;
    cin>>n;
    
    Student* s = new Student[n];
    int count = 0;

    Student s1;
    string name;
    float marks;
    int id, choice;
    do{
        cout<<" 1: Add Student\n 2: Display\n 3: Exit\n"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){

            case 1:
            if(count<n){
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter marks: ";
            cin >> marks;
            s[count].setData(name, id, marks);
            count++;
        }
        else{
            cout<<"No more spaces"<<endl;
        }
            break;

            case 2:
            for(int i = 0; i<count ;i++){
            s[i].display();
        }
            break;

            case 3:
            cout<<"<<Exiting>>"<<endl;
        }
    }while(choice!=3);
    delete []s;
    s = NULL;
    return 0;
}