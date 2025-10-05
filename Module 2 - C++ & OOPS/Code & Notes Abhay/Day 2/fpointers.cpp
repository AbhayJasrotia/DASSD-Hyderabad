/*
        So, basically int *p what does it mean - It simple me that p is an address where int lives ok simple.

        So, what is & - &s but it it - bro its nothing just a simple thing that & give us the address of s.

        Now *p it simple says that access the object at that address.

        Pointer types matter. int* means "address of an int" — pointer arithmetic and dereference obey the type.

        Dynamic memory = rent a house. new rents memory; delete returns it. Forgetting delete = memory leak. 
        Deleting twice = UB (double free). Using after delete = dangling pointer (dangerous).

        Smart pointers = managed rentals. unique_ptr = one tenant. shared_ptr = shared tenancy with reference counting.
*/

// #include<iostream>
// using namespace std;
// int main(){
//     int x = 10;
//     int *p = &x;
//     cout<< p << endl;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int x = 10;
//     int *p = &x;
    
//     cout << "Memory address of x: " << p << endl;
//     cout << "Value at that address: " << *p << endl;  // *p means "value at address p"
//     cout << "Value of x: " << x << endl;
// }


// #include<iostream>
// using namespace std;
// int main(){
//     int arr[3] = {1,2,3};
//     int *p = arr;
//     *p++;
//     cout<<*p<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int arr[3] = {1,2,3};
//     int *p = arr;
//     p++;
//     cout<<*p<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int arr[3] = {1,2,3};
//     int *p = &arr[2];
//     cout<<*p<<endl;
//     return 0;
// }

