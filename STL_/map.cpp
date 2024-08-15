#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, string> m;//key: value pair--> key should be unique and is stored in sorted order of key
    m[1] = "babbar";
    m[13] = "kumar";
    m[2] = "love";
    m.insert({5, "bheem"});
    cout << "before erase" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << "finding -13 → " << m.count(-13) << endl;

    // m.erase (13) ;
    cout << "after erase" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl
         << endl;
    auto it = m.find(5);
    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first<<": "<< (*i).second << endl;
    }


    //lower_bound,upper_bound,erase,size,clear,empty same as others

    //multimap--> sorted order but not unique like set and multi-set
    //unorderedmap--> unique but not sorted like set and unordered-set
}