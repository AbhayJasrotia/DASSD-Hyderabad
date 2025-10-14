#include<iostream>
using namespace std;

class Warrior{
    public:
    string name = "Guts";
    int strength;
    void attack(){
        cout<<"Warrior "<< name <<" attacks with base sword!!"<<endl;
    }
};

class Knight: public Warrior{
    public:
    string title = "Paladin";
    void defend(){
        cout<<title<<" blocks the incoming strick!!"<<endl;
    }
};

class Paladin : public Knight{
    public:
    int holyPower;
    void heal(){
        cout<< name << " use holy power to heal"<<endl;
    }
};

int main(){
    Paladin p1;

    p1.attack();
    p1.defend();
    p1.heal();
    return 0;
}