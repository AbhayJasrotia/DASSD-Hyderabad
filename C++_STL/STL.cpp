#include <bits/stdc++.h>
using namespace std;
int main()
{
    // pair<int,int>p={1,3};
    // cout<<p.first<<" "<<p.second;
    //pair<int,pair<int,int>>p={1,{3,4}};
    //cout <<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
     //pair<int,int>arr[]={{0,1},{1,2},{3,4},{4,6}};
     //cout<<arr[1].first<<" "<<arr[1].second<<endl;


     //vectors

    
     //v.push_back(1);
     //v.emplace_back(2);
     //cout<<v[0]<<" "<<v[1]<<endl;
     //vector<pair<int,int>>v = {{3,4},{1,2}};

     //cout<<v.size()<<endl;
     //cout<<v.capacity()<<endl;

     //iterator-----> Basically it act as an pointer which stores the starting address of element at 0th index
     //Consider an array 20,10,15,6,7 here if we initialize Vector<int>::iterator it=v.begin() it points the starting address of element 20;
    //  vector<int>v={1,2,3,4,5};
    //  vector<int>::iterator it=v.begin();
    //  cout<<*it<<endl;

    //  for(auto it=v.begin();it!=v.end();it++)
    //  {
    //     cout<<*it<<" ";
    //  }
    //  for(auto i:v)
    //  cout<<i<<" ";

    //erase function

    //  vector<int>v={1,2,3,4,5};
    //  v.erase(v.begin()+1,v.begin()+4); // it will delete starting from begin()+1 address and an finally points to before v.begin()+4.
    //  for(auto i:v)
    //  cout<<i<<" ";
      
    //insert function
    //vector<int>v;
    //vector<int>(2,100);{100,100};
    //v.insert(v.begin(),300){300,100,100};
    //v.insert(v.begin()+1,2,10)->(300,10,10,100,100) Here 2 means how many occurence of 10 should be inserted.
    //vector<int>copy(2,50);
    //v.insert(v.begin(),copy.begin(),copy.end());{50,50,300,10,10,100,100};

    //v.pop_back()//pops the last element of the vector
    
    //swap function
    //v1->{10,20};
    //v2->{30,40};
    //v1.swap(v2);  v1->{30,40} v2->{10,20};

    //v.clear() //erases the entire vector.
    //v.empty() returns bool value either 0 or 1.

    
    
    return 0;
}