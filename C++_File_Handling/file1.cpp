#include <bits/stdc++.h>
using namespace std;
int main()
{
    ofstream hout("file.txt");
    string name;
    cout<<"Enter your name"<<endl;
    getline(cin,name);

    hout<<name+"is my name";
    hout.close();
    //for read;

    ifstream hin("file.txt");
    string s;
    
    getline(hin,s);
    cout<<s<<endl;
    hin.close();
return 0;
}