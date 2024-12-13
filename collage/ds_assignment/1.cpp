#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int mostFrequentElement(const vector<int> &nums)
{
    unordered_map<int, int> freqMap;
    int maxFreq = 0;
    int mostFrequent = nums[0];

    for (int num : nums)
    {
        freqMap[num]++;
        if (freqMap[num] > maxFreq)
        {
            maxFreq = freqMap[num];
            mostFrequent = num;
        }
    }

    return mostFrequent;
}

int main()
{
    vector<int> nums = {4, 5, 9, 12, 9, 22, 45, 7};
    cout << "Most frequent element: " << mostFrequentElement(nums) << endl;
    return 0;
}