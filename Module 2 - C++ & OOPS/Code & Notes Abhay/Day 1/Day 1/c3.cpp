//call by value
#include<iostream>
using namespace std;

void changevalue(int x){
    x = 100;
}

int main(){
    int a = 10;
    changevalue(a);
    cout<<a;
    return 0;
}


// call by referance
// #include<iostream>
// using namespace std;

// void changevalue(int &x){
//     x = 100;
// }

// int main(){
//     int a = 10;
//     changevalue(a);
//     cout<<a;
//     return 0;
// }

//call by Pointer

#include <iostream>
using namespace std;

void changeValue(int *x) {
    *x = 100;  // change the value at that memory address
}

int main() {
    int a = 10;
    changeValue(&a);
    cout << a; // Output: 100
    return 0;
}
