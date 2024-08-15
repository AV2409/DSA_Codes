#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;



    l.push_back(1);//emplace_back and front are also there
    l.push_front(2);
    l.push_back(3);


    for(int i:l){
        cout<<i<<" ";
    }

    // cout<<endl<<l.at(2)<<endl; //we cannot do this

    l.pop_back();
cout<<endl;
    for(int i:l){
        cout<<i<<" ";
    }

    l.pop_front();
    cout<<endl;
    for(int i:l){
        cout<<i<<" ";
    }


    list<int>l1(5,40);
    list<int>l2(l1);
    cout<<endl<<"l1: ";
    for(int i:l1){
        cout<<i<<" ";
    }

    cout<<endl<<"l2: ";
    for(int i:l2){
        cout<<i<<" ";
    }

    l1.erase(l1.begin());

    cout<<endl<<"l1: ";
    for(int i:l1){
        cout<<i<<" ";
    }

    l2.insert(l2.begin(),100);
    cout<<endl<<"l2: ";
    for(int i:l2){
        cout<<i<<" ";
    }

    //rest all functions same as vector: clear,begin,erase,inser,begin,end,empty,size
}