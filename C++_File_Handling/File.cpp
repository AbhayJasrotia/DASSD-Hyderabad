#include <iostream>
#include <fstream>
using namespace std;
/*the useful classes for working with files in c++ are
1.fstreambase
2.ifstream derived from fstreambase
3.ofstream derived from fstreambase
*/

//In order to work with files in c++, you will have to open it. there are 2 ways to open afile
//1.using the constructor
//2.Using the memeber function open() of the class
int main()
{
 //opening file using a constructor and writing it.
 string st="Prantik";
 string st2;
//  ofstream out("file.txt"); //write operation
//  out<<st;

//opening file using an constructor and reading it.
ifstream in("file.txt"); 

getline(in,st2);
cout<<st2;


return 0;
}