#include<iostream>
using namespace std;

class Book {
    string title;
    string author;
    float price;
public:
    void input() {
        cout << "Enter title, author and price: ";
        cin >> title >> author >> price;
    }

    void display() {
        cout << "Title: " << title
             << " | Author: " << author
             << " | Price: $" << price << endl;
    }

    float getPrice() {
        return price;
    }
};

int main() {
    Book books[5];
    cout << "Enter details of 5 books:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Book " << i + 1 << ": ";
        books[i].input();
    }

    int index = 0;
    for (int i = 1; i < 5; i++) {
        if (books[i].getPrice() > books[index].getPrice()) {
            index = i;
        }
    }

    cout << "\nBook with highest price:\n";
    books[index].display();

    return 0;
}
