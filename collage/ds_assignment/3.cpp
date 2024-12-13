#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findUniqueInFirstArray(const vector<int> &nums1, const vector<int> &nums2)
{
    unordered_set<int> set2(nums2.begin(), nums2.end());
    vector<int> unique;

    for (int num : nums1)
    {
        if (set2.find(num) == set2.end())
        {
            unique.push_back(num);
        }
    }

    return unique;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 4, 5};

    vector<int> result = findUniqueInFirstArray(nums1, nums2);

    cout << "Unique elements in first array: ";
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}