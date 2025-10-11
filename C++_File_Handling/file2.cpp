#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
  ofstream out;
  out.open("file.txt");
  out<<"This is my name"<<endl;
  out.close();

  ifstream in;
  in.open("file.txt");
  string st;
  while(in.eof()==0)
  {
      getline(in,st);
      cout<<st;
  }
 
  in.close();

return 0;
}