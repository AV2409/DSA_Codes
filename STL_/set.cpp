#include <bits/stdc++.h>
using namespace std;

void explain_unorderedset()

{
    
    //not sorted but unique
    //all other same as set
    //no lowerbound or upper bound function
}


void explain_set()
{
    set<int> s; // unique and sorted
    for (int i = 1; i <= 10; i++)
    {
        s.insert(i);
    }

    cout << "Elements present in the set: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    auto it1 = s.lower_bound(2);
    auto it2 = s.upper_bound(3);
    cout << endl;
    cout << endl
         << "Lower bount of 2: " << *it1 << endl;
    cout << endl
         << "Upper bount of 3: " << *it2 << endl;
    int n = 2;
    if (s.find(2) != s.end())
        cout << n << " is present in set" << endl;

    s.erase(s.begin()); //[start,end),(element)
    cout << "Elements after deleting the first element: ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "The size of the set is: " << s.size() << endl;

    cout << "Count of 5 is: " << s.count(5) << endl;
    cout << "Count of 11 is: " << s.count(11) << endl;

    if (s.empty() == false)
        cout << "The set is not empty " << endl;
    else
        cout << "The set is empty" << endl;
    s.clear();
    cout << "Size of the set after clearing all the elements: " << s.size();
}

void explain_multiset()
{
    multiset<int> ms; // sorted but can store multiple occurances

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    ms.insert(2);
    ms.insert(5);

    for (int i : ms)
    {
        cout << i << " ";
    }

    ms.erase(2); // erases all 2's

    cout << endl
         << "After erasing" << endl;
    for (int i : ms)
    {
        cout << i << " ";
    }

    cout << endl
         << "1's : " << ms.count(1);

    auto it = ms.find(1);

    it++;
    it++;


    ms.erase(ms.find(1), it);
    cout << endl;
    for (int i : ms)
    {
        cout << i << " ";
    }
}

int main()
{
    explain_set();

    // explain_multiset();
}