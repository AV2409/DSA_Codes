#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,int> p;
    pair<int,int> p1;
    pair<int,int> p2={1,2};

    pair<int,pair<int,int> > p3={1,{2,4}};

    p.first=1;
    p.second=2;
    p1.first=3;
    p1.second=4;

    p.swap(p1);

    cout<<p.first<<" "<<p.second<<endl;
    cout<<p1.first<<" "<<p1.second;
    cout<<endl<<p3.first<<" "<<p3.second.first<<" "<<p3.second.first<<endl;

    pair<int,int> arr[2]={{1,2},{2,3}};

    cout<<endl<<arr[0].first<<" "<<arr[0].second;
    cout<<endl<<arr[1].first<<" "<<arr[1].second;
}

