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
            cout<<"Enter title ,author, price of book: "<<endl;
            cin>>title>>author>>price;
        }
        
        void display(){
            cout<<"Title of book is "<<title<<" || author's name is "
            <<author<<" || and book's price is $"<<price<<endl;
        }
};

int main(){
    int n;
    cout<<"Enter total no. of books to store: "<<endl;
    cin>>n;
    Book* bptr = new Book[n];
    for(int i = 0; i<n;i++){
        cout<<"Enter books details "<<i+1<<endl;
        bptr[i].input();
    }
    for(int i = 0; i<n;i++){
        cout<<"Displaying the books: "<<i+1<<endl;
        bptr[i].display();
    }
    delete[] bptr;
    bptr = nullptr; 
    return 0;
}