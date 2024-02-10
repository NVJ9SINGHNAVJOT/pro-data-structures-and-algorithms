#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm: binary search
// question: find peak element in array
// example: vector<int> arr = {1,4,5,9,55,88,95,120,100,65,41,23,6}
// answer: ans = 120
// explanation: peak element is a element in array which is greater from previous and next index elements
// tags:

int findPeakElement(vector<int> &nums)
{
    int ans = -1;
    int s = 0;
    int e = nums.size() - 1;
    int m = (s + e) / 2;

    while (s <= e)
    {
        int element = nums[m];
        if (element > nums[m + 1])
        {
            ans = element;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
        m = (s + e) / 2;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,4,5,9,55,88,95,120,100,65,41,23,6};
    int ans = findPeakElement(nums);
    cout<<ans<<endl;
    return 0;
}