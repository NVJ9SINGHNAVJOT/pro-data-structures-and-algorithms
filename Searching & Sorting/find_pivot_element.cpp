#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm: binary search
// question: find pivot element in array
// example: vector<int> arr = {55,88,95,120,2,6,19,38,50}
// answer: ans = 120
// explanation: pivot element is a element in array which is greater from previous and next index elements
// tags:

int findPivotElement(vector<int> &nums)
{
    int ans = -1;
    int s = 0;
    int e = nums.size() - 1;
    int m = (s + e) / 2;

    while (s <= e)
    {
        if ( m +1 < nums.size() && nums[m] > nums[m + 1])
        {
            ans = nums[m];
            return ans;
        }
        else if (m -1 >= 0 && nums[m-1] > nums[m])
        {
            ans = nums[m-1];
            return ans;
        }
        else if (nums[s] > nums[m])
        {
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
    vector<int> nums = {55,88,95,140,2,6,19,38,50};
    int ans = findPivotElement(nums);
    cout<<ans<<endl;
    return 0;
}