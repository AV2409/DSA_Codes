#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void findUnionAndIntersection(const vector<int> &list1, const vector<int> &list2)
{
    unordered_set<int> set1(list1.begin(), list1.end());
    unordered_set<int> set2(list2.begin(), list2.end());

    // Intersection
    cout << "Intersection: ";
    for (const int &num : set1)
    {
        if (set2.find(num) != set2.end())
        {
            cout << num << " ";
        }
    }

    // Union
    cout << "\nUnion: ";
    for (const int &num : set1)
    {
        cout << num << " ";
    }

    for (const int &num : set2)
    {
        if (set1.find(num) == set1.end())
        {
            cout << num << " ";
        }
    }
}

int main()
{
    vector<int> list1 = {1, 2, 3};
    vector<int> list2 = {3, 4, 5};

    findUnionAndIntersection(list1, list2);

    return 0;
}