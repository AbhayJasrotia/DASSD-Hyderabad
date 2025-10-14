#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
        string title;
        float price;
    public:
      Book(string t = "", float p=0.0f){
        title = t;
        price = p;
      }

    void display(){
        cout<<"Title: "<<title;
        cout<<"Price $ "<<price;
        cout<<"----------------"<<endl;
    }

    void input(){
        cout<<"Enter book name: ";
        getline(cin,title);
        cout<<"Enter the price: ";
        cin>>price;
        cin.ignore();
    }
};

int main(){
    Book* bookptr = new Book();
    cout<<"Enter book details:"<<endl;
    bookptr->input();
    cout<<endl;
    cout<<"Book details: "<<endl;
    bookptr->display();
    delete bookptr;
    return 0;
}