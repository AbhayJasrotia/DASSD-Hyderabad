#include <iostream>
#include <string>
using namespace std;

class Warrior {
    int age;
    int strength;
    int wisdom;
    int wealth;
    string mindset;

public:
    Warrior(int a, int s, int w, int m, string mind)
        : age(a), strength(s), wisdom(w), wealth(m), mindset(mind) {}

    void train(int sGain, int wGain, int mGain) {
        strength += sGain;
        wisdom += wGain;
        wealth += mGain;
        cout << "Training completed. Strength and wisdom sharpened.\n";
    }

    void display() {
        cout << "Age: " << age << " | Strength: " << strength
             << " | Wisdom: " << wisdom << " | Wealth: " << wealth
             << "\nMindset: " << mindset << endl;
        cout << "--------------------------------------" << endl;
    }

    void evolve(string newMindset) {
        mindset = newMindset;
        age += 3; // time passes as he evolves
        cout << "The warrior has endured 3 more years.\n";
    }
};

int main() {
    Warrior abhay(23, 30, 10, 0, "Lost but not broken");
    abhay.display();

    abhay.train(20, 15, 50000);
    abhay.evolve("Focused and disciplined");
    abhay.display();

    abhay.train(25, 20, 70000);
    abhay.evolve("Calm, strong, and grounded");
    abhay.display();

    abhay.train(30, 25, 150000);
    abhay.evolve("Unshakable — a master of self");
    abhay.display();

    cout << "The path was long, but the man was longer.\n";
    cout << "No woman, no luxury, no luck — only will.\n";

    return 0;
}
