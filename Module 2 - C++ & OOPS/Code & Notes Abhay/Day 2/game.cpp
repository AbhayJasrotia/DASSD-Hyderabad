#include <iostream>
using namespace std;

class Swordsman
{
private:
    string name;
    int health;
    float stamina;

protected:
    string rank = "Knight";

public:
    // Parameterized constructor
    Swordsman(string n, int h, float s){
        name = n;
        health = h;
        stamina = s;
        cout<<"⚔️ Summoning Swordsman: " << name << " has entered the battlefield!"<<endl;
        
        // Auto-check on creation
        if(health < 10) {
            cout<<"💊 Auto-healing " << name << " from critical health!"<<endl;
            health = 100;
        }
        if(stamina < 10) {
            cout<<"⚡ Auto-restoring " << name << " from critical stamina!"<<endl;
            stamina = 50;
        }
    }

    // Copy Constructor
    Swordsman(const Swordsman &org){
        name = org.name;
        health = org.health;
        stamina = org.stamina;
         cout << "🪞 Mirror clone of " << name 
         << " has joined the battlefield!" << endl;
    }

    void showStats(){
        cout<<"Swordsman name is "<< name << " his health is " 
        << health << " and stamina is "<<stamina<<endl;
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
        else{
            // Default attack for other swordsmen
            if(stamina >= 90){
                cout<<name<<": Ultimate Sword Technique!"<<endl;
            }
            else if(stamina >= 45){
                cout<<name<<": Basic Sword Attack!"<<endl;
            }
            else{
                cout<<name<<": Too tired to attack!"<<endl;
            }
        }
    }

    // GETTERS - Correct return types
    // string getName(){
    //     return name;
    // }

    // int getHealth(){
    //     return health;
    // }

    // float getStamina(){
    //     return stamina;
    // }

    // SETTERS - Auto-heal and auto-rest features
    void setHealth(int h){
        health = h;
        if(health < 10){
            cout<<"💊 "<< name << " is critically low! Auto-healing to 100!"<<endl;
            health = 100;
        }
    }

    void setStamina(float s){
        stamina = s;
        if(stamina < 10){
            cout<<"⚡ "<< name << " is exhausted! Auto-restoring to 50!"<<endl;
            stamina = 50;
        }
    }

    ~Swordsman(){
        cout<<"😁👍 Swordsman " << name << " has lost interest..."<<endl;
    }
};

int main()
{
    Swordsman s1("Zoro", 1000, 1);
    s1.showStats();
    s1.attack();
    
    Swordsman s2(s1);
    s2.showStats();
    s2.attack();
    // cout << "Name: " << s1.getName() << endl;
    // cout << "Health: " << s1.getHealth() << endl;
    // cout << "Stamina: " << s1.getStamina() << endl;

    return 0;
}