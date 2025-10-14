// #include<iostream>
// using namespace std;

// class store{
//     int itemID[100];
//     int itemPrice[100];
//     int counter;

//     public:
//         void initCounter(void){
//             counter = 0;
//         }
//         void setip(void);
//         void displayip(void);
// };

// void store :: setip(void){
//     cout<<"Enter item ID no"<< counter + 1 <<endl;
//     cin>>itemID[counter];
//     cout<<"Enter item Price"<<endl;
//     cin>>itemPrice[counter];
//     counter++;
// }

// void store :: displayip(void){
//     for(int i = 0; i < counter; i++ ) {
//         cout<<"Price of item with ID "<<itemID[i]<<" is "<< itemPrice[i]<<endl; 
//     }
// }

// int main(){
//     store aj;
//     aj.initCounter();
//     aj.setip();
//     aj.setip();
//     aj.displayip();
//     return 0; 
// }


#include <iostream>
using namespace std;

class Shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void setPrice(void);
    void displayPrice(void);
};

void Shop :: setPrice(void)
{
    cout << "Enter Id of your item no " << counter + 1 << endl;
    cin >> itemId[counter];
    cout << "Enter Price of your item" << endl;
    cin >> itemPrice[counter];
    counter++;
}

void Shop :: displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The Price of item with Id " << itemId[i] << " is " << itemPrice[i] << endl;
    }
}

int main()
{
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();
    return 0;
}

