#include <iostream>
#include<vector>
using namespace std;

int main()
{

    vector<int> nums={3,4,5,1,2};
    int s = 0;
    int e = nums.size() - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] <= nums[0])
        {
            s = mid + 1;
        }

        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    int ans = nums[mid];

    cout<<ans;
}


