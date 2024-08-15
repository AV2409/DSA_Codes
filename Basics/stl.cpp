#include<bits/stdc++.h>
using namespace std;

void pairs(){
    pair<int,int> p={1,2};
    cout<<p.first<<" "<<p.first;

    cout<<endl;
    pair<int,pair<int,int>> g={1,{3,2}};
    cout<<g.first<<" "<<g.second.first<<" "<<g.second.second;

    cout<<endl;

    pair<int,int> arr[]={{1,2},{3,5},{4,3}};
    cout<<arr[0].first<<" "<< arr[1].first;
}

void vectors(){
    vector<int> v1(5,20),v2;
    cout<<v1[1];
    v2={1,2,3,4,5};
    cout<<endl<<v2[3];

    vector<int> v3(v2);
    cout<<endl<<v3[0];

    v3.emplace_back(3);
    v2.push_back(2);

    cout<<endl<<v2[5]<<" "<<v3[5];


}

int main(){
    // pairs();
    vectors();
    return 0;
}