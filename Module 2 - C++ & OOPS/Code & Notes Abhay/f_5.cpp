#include <iostream>
#include <string>
using namespace std;

// ===============================
// Base Class: Item
// ===============================
class Item {
private:
    string name;
    int id;
    float price;

protected:
    int quantity;

public:
    // Parameterized Constructor
    Item(string n, int i, float p, int q) {
        name = n;
        id = i;
        price = p;
        quantity = q;
    }

    // Display basic item info
    void display() {
        cout << "Item Name: " << name << endl;
        cout << "Item ID: " << id << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Value: " << getTotalValue() << endl;
    }

    // Calculate total value (price × quantity)
    float getTotalValue() {
        return price * quantity;
    }

    // Getter for ID (optional)
    int getId() {
        return id;
    }

    // Destructor
    ~Item() {
        cout << "Base Item (ID " << id << ") destroyed.\n";
    }
};

// ===============================
// Derived Class: Electronics
// ===============================
class Electronics : public Item {
private:
    int warrantyYears;
    float powerUsage;

public:
    // Constructor using initializer list
    Electronics(string n, int i, float p, int q, int warranty, float power)
        : Item(n, i, p, q), warrantyYears(warranty), powerUsage(power) {}

    // Display all details
    void displayDetails() {
        cout << "\n--- Electronics Item ---" << endl;
        display(); // call base class display
        cout << "Warranty (years): " << warrantyYears << endl;
        cout << "Power Usage (Watts): " << powerUsage << endl;
        cout << "---------------------------" << endl;
    }

    // Destructor
    ~Electronics() {
        cout << "Electronics item destroyed.\n";
    }
};

// ===============================
// Derived Class: Grocery
// ===============================
class Grocery : public Item {
private:
    string expiryDate;
    float weight;

public:
    // Constructor
    Grocery(string n, int i, float p, int q, string expiry, float w)
        : Item(n, i, p, q), expiryDate(expiry), weight(w) {}

    // Display all details
    void displayDetails() {
        cout << "\n--- Grocery Item ---" << endl;
        display(); // call base display
        cout << "Expiry Date: " << expiryDate << endl;
        cout << "Weight (kg): " << weight << endl;
        cout << "---------------------" << endl;
    }

    // Destructor
    ~Grocery() {
        cout << "Grocery item destroyed.\n";
    }
};

// ===============================
// Main Function
// ===============================
int main() {
    int numItems;
    cout << "Enter total number of items in inventory: ";
    cin >> numItems;

    // Array of base class pointers (can store any derived class)
    Item** inventory = new Item*[numItems];

    float totalInventoryValue = 0;

    for (int i = 0; i < numItems; i++) {
        int category;
        cout << "\nEnter details for item " << (i + 1) << endl;
        cout << "Choose Category: 1 = Electronics, 2 = Grocery: ";
        cin >> category;

        string name;
        int id, quantity;
        float price;

        cout << "Enter Item Name: ";
        cin >> name;
        cout << "Enter Item ID: ";
        cin >> id;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;

        if (category == 1) {
            int warranty;
            float power;
            cout << "Enter Warranty (in years): ";
            cin >> warranty;
            cout << "Enter Power Usage (Watts): ";
            cin >> power;

            // Create Electronics object dynamically
            Electronics* e = new Electronics(name, id, price, quantity, warranty, power);
            inventory[i] = e; // store in base class pointer
            totalInventoryValue += e->getTotalValue();

        } else {
            string expiry;
            float weight;
            cout << "Enter Expiry Date: ";
            cin >> expiry;
            cout << "Enter Weight (kg): ";
            cin >> weight;

            // Create Grocery object dynamically
            Grocery* g = new Grocery(name, id, price, quantity, expiry, weight);
            inventory[i] = g;
            totalInventoryValue += g->getTotalValue();
        }
    }

    // Display all items
    cout << "\n========== INVENTORY DETAILS ==========\n";
    for (int i = 0; i < numItems; i++) {
        // Use static_cast to call correct displayDetails() since no virtual functions
        // (must manually cast to the right type)
        cout << "--------------------------------------" << endl;

        // Try to safely check what kind of object it is (by asking user earlier)
        // In this simple case, we can just ask user to recall order of inputs.
        // But let's demonstrate both casts:
        Electronics* e = dynamic_cast<Electronics*>(inventory[i]);
        Grocery* g = dynamic_cast<Grocery*>(inventory[i]);

        if (e != nullptr)
            e->displayDetails();
        else if (g != nullptr)
            g->displayDetails();
    }

    cout << "\nTotal Inventory Value: " << totalInventoryValue << endl;

    // Cleanup memory
    for (int i = 0; i < numItems; i++) {
        delete inventory[i];
    }
    delete[] inventory;

    cout << "\nAll inventory data cleared safely.\n";

    return 0;
}
