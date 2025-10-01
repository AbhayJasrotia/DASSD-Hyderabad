// #include<iostream>
// using namespace std;

// struct student{
//     int id;
//     char grade;
//     float marks;
// };

// int main(){
//     struct student Abhay;
//     struct student Patrick;
//     Abhay.id = 1;
//     Abhay.grade = 'A';
//     Abhay.marks = 85.77;

//     Patrick.id = 2;
//     Patrick.grade = 'B';
//     Patrick.marks = 93.99;

//     cout<<Abhay.id<<" "<<Abhay.grade<<" "<<Abhay.marks<<endl;
//     cout<<Patrick.id<<" "<<Patrick.grade<<" "<<Patrick.marks<<endl;

//     return 0;
// }

#include<iostream>
using namespace std;

struct student{
    int id;
    char grade;
    float marks;
};

int main(){
    struct student Abhay;
    struct student Patrick;
    Abhay.id = 1;
    Abhay.grade = 'A';
    Abhay.marks = 85.77;

    Patrick.id = 2;
    Patrick.grade = 'B';
    Patrick.marks = 93.99;

    cout<<Abhay.id<<" "<<Abhay.grade<<" "<<Abhay.marks<<endl;
    cout<<Patrick.id<<" "<<Patrick.grade<<" "<<Patrick.marks<<endl;

    return 0;
}  