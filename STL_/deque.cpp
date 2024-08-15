#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d;



    d.push_back(1);//emplace_back and front are also there
    d.push_front(2);
    d.push_back(3);


    for(int i:d){
        cout<<i<<" ";
    }

    cout<<endl<<d.at(2)<<endl;

    d.pop_back();

    for(int i:d){
        cout<<i<<" ";
    }

    d.pop_front();
    cout<<endl;
    for(int i:d){
        cout<<i<<" ";
    }

    //rest all functions same as vector: clear,begin,erase,inser,begin,end,empty,size
}