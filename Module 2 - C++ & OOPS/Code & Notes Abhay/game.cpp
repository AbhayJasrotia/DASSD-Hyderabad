#include <iostream>
using namespace std;

class Swordsman
{
private:
    string name;
    int *health;  // Dynamic health
    float stamina;

protected:
    string rank = "Knight";

public:
    // Parameterized constructor
    Swordsman(string n, int h, float s){
        name = n;
        health = new int(h);  // Allocate memory for health
        stamina = s;
        cout<<"⚔️ Summoning Swordsman: " << name << " has entered the battlefield!"<<endl;
        
        // Auto-check on creation - FIXED
        if(*health < 10) {  // ✅ Dereference pointer to get value
            cout<<"💊 Auto-healing " << name << " from critical health!"<<endl;
            *health = 100;
        }
        if(stamina < 10) {
            cout<<"⚡ Auto-restoring " << name << " from critical stamina!"<<endl;
            stamina = 50;
        }
    }

    // ✅ CORRECT Deep Copy Constructor
    Swordsman(const Swordsman &org){
        name = org.name + "_Clone";
        health = new int(*(org.health));  // ✅ DEEP COPY - new memory
        stamina = org.stamina;
        cout << "🪞 Mirror clone of " << org.name 
             << " has joined the battlefield!" << endl;
    }

    void showStats(){
        cout<<"Swordsman name is "<< name << " his health is " 
        << *health << " and stamina is "<<stamina<<endl;  // ✅ Dereference
    }

    void attack(){
        if(name == "Zoro"){
            if(stamina >= 90){
                cout<<name<<": Ahaaaaaaaaa King of Hell!"<<endl;
            }
            else if(stamina >= 45){
                cout<<name<<": Ahaaaaaa Oni Giri!"<<endl;
            }
            else{
                cout<<name<<": Shit out of Haki!!!!"<<endl;
            }
        }
        else if(name == "Guts"){
            if(stamina >= 90){
                cout<<name<<": RAAAAAH! Greatsword Combo!"<<endl;
            }
            else if(stamina >= 45){
                cout<<name<<": HAAAA! Berserker Slash!"<<endl;
            }
            else{
                cout<<name<<": Too wounded to fight properly!"<<endl;
            }
        }
    }

    // ✅ CORRECT Setters
    void setHealth(int h){
        *health = h;  // ✅ Dereference to set value
        if(*health < 10){  // ✅ Dereference to check value
            cout<<"💊 "<< name << " is critically low! Auto-healing to 100!"<<endl;
            *health = 100;
        }
    }

    void setStamina(float s){
        stamina = s;
        if(stamina < 10){
            cout<<"⚡ "<< name << " is exhausted! Auto-restoring to 50!"<<endl;
            stamina = 50;
        }
    }

    // ✅ Add assignment operator to prevent issues
    Swordsman& operator=(const Swordsman& other) {
        if(this != &other) {  // Prevent self-assignment
            name = other.name;
            *health = *(other.health);  // Copy value, not pointer
            stamina = other.stamina;
        }
        return *this;
    }

    // ✅ Destructor - free allocated memory
    ~Swordsman(){
        delete health;  // ✅ Free the dynamically allocated memory
        cout<<"😁👍 Swordsman " << name << " has lost interest..."<<endl;
    }
};

int main()
{
    Swordsman s1("Zoro", 1000, 99);
    s1.showStats();
    s1.attack();
    
    cout << "\n--- Creating Clone ---" << endl;
    Swordsman s2(s1);  // Deep copy
    s2.showStats();
    s2.attack();

    cout << "\n--- Testing Independence ---" << endl;
    s1.setHealth(5);  // Should auto-heal s1 only
    s2.setHealth(800); // Should set s2 only
    
    s1.showStats();
    s2.showStats();

    return 0;
}