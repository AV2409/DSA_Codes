#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{

    if (p1.second < p2.second)
        return true;

    if (p1.second > p2.second)
        return false;

    if (p1.first > p2.first)
        return true;

    return false;
}

int main()
{
    vector<int> v = {1, 2, 3, 6, 7, 9};

    cout << "Finding 9: " << binary_search(v.begin(), v.end(), 9) << endl;
    cout << "Finding 10: " << binary_search(v.begin(), v.end(), 10) << endl;

    cout << "upperbound of 6: " << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    cout << "upperbound of 6: " << *upper_bound(v.begin(), v.end(), 6) << endl;

    cout << "lowebound of 6: " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    cout << "lowebound of 6: " << *lower_bound(v.begin(), v.end(), 6) << endl;

    // min(a,b),max(a,b),swap(a,b)

    string s = "abcd";

    reverse(s.begin(), s.end());

    cout << endl
         << s << endl;

    rotate(v.begin(), v.begin() + 2, v.end());

    for (auto i : v)
    {
        cout << i << " ";
    }

    sort(v.begin(), v.end()); //[start,end)

    cout << endl
         << endl;

    for (auto i : v)
    {
        cout << i << " ";
    }

    sort(v.begin(), v.end(), greater<int>());

    cout << endl
         << endl;

    for (auto i : v)
    {
        cout << i << " ";
    }

    cout << endl
         << endl;

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

    sort(a, a + 3, comp);

    for(int i=0;i<3;i++){
        cout<<"{"<<a[i].first<<","<<a[i].second<<"}"<<" ";
    }

    cout << endl;


    cout<<"number of set bits of 7: "<<__builtin_popcount(7)<<endl;

    cout<<"number of set bits of 6: "<<__builtin_popcount(6)<<endl;

    long long n=1235321234532;

    cout<<"number of set bits of n=1235321234532: "<<__builtin_popcountll(n)<<endl;

    cout<<endl<<endl;

    string s1="435";

    sort(s1.begin(),s1.end());

    do{
        cout<<s1<<" ,";
    }while(next_permutation(s1.begin(),s1.end()));

    int arr[5]={1,5,3,8,4};
    vector<int> v1={1,5,3,8,4};


    int maxi=*max_element(arr,arr+5);

    int mini=*min_element(arr,arr+5);

    // int maxi=*max_element(v1.begin(),v1.begin()+5);

    // int mini=*min_element(v1.begin(),v1.begin()+5);

    cout<<endl<<"maxi= "<<maxi;

    cout<<endl<<"mini= "<<mini;

    return 0;
}