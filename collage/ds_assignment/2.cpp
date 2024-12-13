#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool hasPairWithSum(const vector<int> &arr, int target)
{
    unordered_map<int, bool> seen;

    for (int num : arr)
    {
        int complement = target - num;
        if (seen[complement])
        {
            return true; // Pair found
        }
        seen[num] = true;
    }

    return false; // No pair found
}

int main()
{
    vector<int> arr = {-2, 8, 1, 15};
    int target = 9;
    cout << (hasPairWithSum(arr, target) ? "YES" : "NO") << endl;
    return 0;
}