#include <bits/stdc++.h>
using namespace std;
class Item
{
    string name;
    int id;
    float price;

protected:
    int quantity;

public:
    Item(string n, int i, float p, int q)
    {
        this->name = n;
        this->id = i;
        this->price = p;
        this->quantity = q;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
    float getTotalvalue()
    {
        return price * quantity;
    }
    ~Item()
    {
        cout << "Item Class Destructor Called" << endl;
    }
};
class Electronics : public Item
{
    int warranty_year;
    int power_usage;

public:
    Electronics(string s, int i, float p, int q, int wy, int pu) : Item(s, i, p, q)
    {
        warranty_year = wy;
        power_usage = pu;
    }
    void displaydetails()
    {
        cout << "Category electronics" << endl;
        display();
        cout << "Warranty year of the electronics is " << warranty_year << endl;
        cout << "Power Usage of the electronics is " << power_usage << endl;
    }
    ~Electronics()
    {
        cout << "Electronics Clas Destructor called" << endl;
    }
};
class Grocery : public Item
{
    string expiry_date;
    float weight;

public:
    Grocery(string s, int i, float p, int q, string str1, float w) : Item(s, i, p, q)
    {
        expiry_date = str1;
        weight = w;
    }
    void displaydetails()
    {
        cout << "Grocery Items" << endl;
        display();
        cout << "Expiry_Date of the product is" << expiry_date << endl;
        cout << "Weight of the item is " << weight << endl;
    }
    ~Grocery()
    {
        cout << "Grocery Destructor called" << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the total number of items: ";
    cin >> n;
    int numElectronics = 0, numGroceries = 0;

    // First pass to determine counts
    for (int i = 0; i < n; i++)
    {
        int category;
        cout << "Enter category for item " << (i + 1)
             << " (1 - Electronics, 2 - Grocery): ";
        cin >> category;

        if (category == 1)
            numElectronics++;
        else if (category == 2)
            numGroceries++;
    }
    Electronics **electronicsItems = new Electronics *[numElectronics];
    Grocery **groceryItems = new Grocery *[numGroceries];
    int eIndex = 0, gIndex = 0;
    float totalInventoryValue = 0.0f;
    for (int i = 0; i < n; i++)
    {
        int category;
        cout << "\nItem #" << (i + 1) << ":\n";
        cout << "Enter category (1 - Electronics, 2 - Grocery): ";
        cin >> category;

        string name;
        int id, quantity;
        float price;

        cout << "Enter name: ";
        cin.ignore(); // ignore leftover newline
        getline(cin, name);

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter quantity: ";
        cin >> quantity;

        if (category == 1)
        {
            int warranty;
            int power;
            cout << "Enter warranty years: ";
            cin >> warranty;
            cout << "Enter power usage (Watts): ";
            cin >> power;

            electronicsItems[eIndex] = new Electronics(name, id, price, quantity, warranty, power);
            totalInventoryValue += electronicsItems[eIndex]->getTotalvalue();
            eIndex++;
        }
        else if (category == 2)
        {
            string expiry_date;
            float weight;
            cout << "Enter expiry date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, expiry_date);
            cout << "Enter weight (kg): ";
            cin >> weight;

            groceryItems[gIndex] = new Grocery(name, id, price, quantity, expiry_date, weight);
            totalInventoryValue += groceryItems[gIndex]->getTotalvalue();
            gIndex++;
        }
    }

    cout << "\nTotal Inventory Value: $" << totalInventoryValue << endl;
    // Display all details
    cout << "\n================== INVENTORY DETAILS ==================\n";
    for (int i = 0; i < numElectronics; i++)
    {
        electronicsItems[i]->displaydetails();
    }

    for (int i = 0; i < numGroceries; i++)
    {
        groceryItems[i]->displaydetails();
    }

    cout << "\nTotal Inventory Value = " << totalInventoryValue << endl;

    // Cleanup memory
    for (int i = 0; i < numElectronics; i++)
    {
        delete electronicsItems[i];
    }
    for (int i = 0; i < numGroceries; i++)
    {
        delete groceryItems[i];
    }

    delete[] electronicsItems;
    delete[] groceryItems;

    cout << "\nAll dynamically allocated memory cleaned successfully.\n";
    return 0;

    return 0;
}
