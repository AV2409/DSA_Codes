#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;

    vector<pair<int, int>> v1;

    v1.push_back({1, 2});
    v1.emplace_back(3, 4);

    cout << v1[0].first << " " << v1[0].second << endl;
    cout << v1[1].first << " " << v1[1].second << endl;

    

    cout << endl
         << "Capacity/memory: " << v.capacity(); // memory allocated

    v.push_back(1);
    cout << endl
         << "Capacity/memory: " << v.capacity();

    v.emplace_back(2);//faster
    cout << endl
         << "Capacity/memory: " << v.capacity();

    v.push_back(3);
    cout << endl
         << "Capacity/memory: " << v.capacity();
    cout << endl
         << "Size: " << v.size();

    v.push_back(4);
    v.push_back(5);
    cout << endl
         << "Capacity/memory: " << v.capacity();
    cout << endl
         << "Size: " << v.size();

    cout << endl
         << "Element at index 2: " << v.at(2);
    cout << endl
         << "Array is empty: " << v.empty();
    cout << endl
         << "First element: " << v.front();
    cout << endl
         << "last element: " << v.back();

    cout << endl;

    cout << "Before pop: ";
    for (int i : v)
    {
        cout << i << " ";
    }

    cout << endl;

    v.pop_back();

    cout << "After pop: ";
    for (int i : v)
    {
        cout << i << " ";
    }

    // cout << endl
    //      << endl
    //      << "Size of the vector befor clearing the vector: " << v.size();
    // cout << endl
    //      << "Capacity of the vector after clearing the vector: " << v.capacity();
    // v.clear();
    // cout << endl
    //      << endl
    //      << "Size of the vector after clearing the vector: " << v.size();
    // cout << endl
    //      << "Capacity of the vector after clearing the vector: " << v.capacity();

    vector<int> a(5, 1);
    vector<int> last(a); // copies a to last

    cout << endl
         << "a: ";
    for (int i : a)
    {
        cout << i << " ";
    }

    cout << endl
         << "last: ";
    for (int i : last)
    {
        cout << i << " ";
    }

    cout << "\nInserting 5 at the beginning:" << endl;
    v.insert(v.begin(), 5);
    cout << "The first element is: " << v[0] << endl;

    cout << endl; 

    cout << "Erasing the first element" << endl;
    v.erase(v.begin());
    v.erase(v.begin()+1);
    v.erase(v.begin()+1,v.begin()+3);       //[start,end)
    cout << "Now the first element is: " << v[0] << endl;

    vector<int> :: iterator it=v.begin();

    cout<<endl<<*(it);
    it++;
    cout<<endl<<*(it);
    vector<int> :: iterator it1=v.end();
    it--;
    cout<<endl<<*(it1);

    cout << endl
         << "the elements in the vector: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";

    cout << endl
         << "the elements in the vector: ";
    for (    vector<int> :: iterator it=v.begin(); it != v.end(); it++)
        cout << *it << " ";

    
    cout << endl<< "the elements in the vector: ";
    for (int i : v)
    {
        cout << i << " ";
    }

    //insert function

    vector<int> v2(2,100);
    v2.insert(v2.begin(),300);//{300,100,100}
    v2.insert(v2.begin()+2,2,50);//{300,100,50,50,100}

    cout << endl<< "the elements in the vector: ";
    for (int i : v2)
    {
        cout << i << " ";
    }
    vector<int> c1(2,75);

    v2.insert(v2.begin()+1,c1.begin(),c1.end());

    cout << endl<< "the elements in the vector: ";
    for (int i : v2)
    {
        cout << i << " ";
    }

    sort(v2.begin(),v2.end());

    cout << endl<< "the elements in the vector: ";
    for (int i : v2)
    {
        cout << i << " ";
    }

    

//     v1.swap(v2);//swapping function


}