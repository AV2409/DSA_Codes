#include <bits/stdc++.h>
using namespace std;

class Act
{
public:
    int start;
    int finish;
};

bool activityCompare(Act s1, Act s2)
{
    return (s1.finish < s2.finish);
}

void printMaxActivities(vector<Act> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), activityCompare);

    cout << "Following activities are selected :\n";
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish
         << ")";

    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << ", (" << arr[j].start << ", "
                 << arr[j].finish << ")";
            i = j;
        }
    }
}

int main()
{
    vector<Act> arr = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    printMaxActivities(arr);
    return 0;
}
