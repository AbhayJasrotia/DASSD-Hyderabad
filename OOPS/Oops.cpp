#include <bits/stdc++.h>
using namespace std;
class Hero
{ 
    //By default class takes access modifier as private;
    //properties or Data Members
    private:
    int health;
    char level;
    public:
    char *name;
   Hero()
   {
    cout<<"Constructor Called"<<endl;
    name=new char[50];
   }

  //Parametereized Constructor
  Hero(int health,char level)
  {
    cout<<"this-->"<<this<<endl;
    this->health=health;
    this->level=level;
  }

  Hero (Hero& temp)
  {
      char *ch=new char[strlen(temp.name)+1];
      strcpy(ch,temp.name);
      this->name=ch;
      this->health=temp.health;
      this->level=temp.level;
  }


     void print()
     {
        cout<<"Health is "<<this->health<<endl;
        cout<<"Level is "<<this->level<<endl;
        cout<<"Name is "<<this->name<<endl<<endl;
     }

    int gethealth()
    {
       return health;
    }

    char getlevel()
    {
        return level;
    }
 
    void sethealth(int h){
        health=h;
    }

    void setlevel(char ch)
    {
        level=ch;
    }

    void setname(char name[])
    {
        strcpy(this->name,name);
    }

};
int main()
{
     
    //static allocation
    //Hero h1;
    //cout<<sizeof(h1); // for an empty class size will be of 1bytes.
    //h1.name=(char*)malloc(5*sizeof(char)); using c
    // h1.name=new char[5];
    // for(int i=0;i<5;i++)
    // {
    //     cin>>h1.name[i];
    // }
 
    //   h1.sethealth(70);   //Thereby to access private members of a class through main we can use getter and setter method
    //   cout<<"Ramesh health is "<<h1.gethealth()<<endl;
    //   h1.setlevel('A');
    //   cout<<"Ramesh level is "<<h1.getlevel()<<endl;
    //dynamic allocation;
    // Hero *h1=new Hero;
    // (*h1).sethealth(70);
    // cout<<"Ramesh health is "<<(*h1).gethealth()<<endl; //Both we can use

    // h1->sethealth(50);
    // cout<<"Ramesh health is "<<h1->gethealth()<<endl;   //Both we can use
    
    //Default Constructor
    // It will invoke at object creation time
    //No return type
    //No i/p parameters
   // Hero ramesh;  //using statically
    //Hero *h=new Hero();//using dynamically

    //Parameterized Constructor
    //Hero tt; //If you declare your own default constructor then system default constructor automaticaly gets wiped out.
    //  Hero ramesh(10,'A');
    //  cout<<"Address of ramesh "<<&ramesh<<endl;
    //  cout<<ramesh.gethealth()<<endl;
    // cout<<ramesh.getlevel()<<endl;

    //  Hero *h1=new Hero(50,'A');
    //  cout<<h1->gethealth()<<endl;
    //  cout<<h1->getlevel()<<endl;


     //Copy Constructor
    //   Hero s(70,'C');
    //   s.print();
    //   Hero r(s);------>>>r.health=s.health & r.level=s.level
    //   r.print();

    Hero h1;
   h1.sethealth(70);
   h1.setlevel('A');
   char name[8]="Prantik";
   h1.setname(name);

   h1.print();
      
   Hero h2(h1);
   h2.print();

   h1.name[0]='G';
   h1.print();
   h2.print();
    return 0;

}