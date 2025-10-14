#include<iostream>
using namespace std;

class Book{
    private:
        string title;
        string author;
        float price;
    
    public:
        void setdata(string t, string a, float p){
            title = t;
            author = a;
            price = p;
        }

        void input(){
            cout<<"Enter title of book: "<<endl;
            cin>>title;
            cout<<"Enter author of book: "<<endl;
            cin>>author;
            cout<<"Enter price of book : "<<endl;
            cin>>price;
        }

        void display(){
            cout<<title<<"|"<<author<<"|"<<price<<endl;
        }

        void maxPrice(){

        }
        // float getPrice(){
        //     return price;
        // }


};

int main(){
    int n;
    cout<<"Enter total books : "<<endl;
    cin>>n;
    Book* ptr = new Book[n];
    for(int i = 0; i<n; i++){
        cout<<"Enter books details"<<endl;
        ptr[i].input();
    }

    // int mi = 0;
    // float mp = ptr[0].getPrice();
    // for(int i = 0; i<n ; i++){
    //     if(ptr[i].getPrice()>mp){
    //         mp = ptr[i].getPrice();
    //         mi = i;
    //     }
    // }
    cout << "\nAll Books:" << endl;
    for(int i = 0; i < n; i++){
        ptr[i].display();
    }
    // cout<<"Book with highest price"<<endl;
    // ptr[mi].display();

    return 0;
}