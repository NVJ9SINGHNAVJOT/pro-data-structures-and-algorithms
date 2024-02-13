#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: house robber
// example:
// answer:
// explanation:
// tags:

int robHelper(vector<int> &nums, int i)
{
    if (i >= nums.size())
    {
        return 0;
    }

    // sol for one case

    int robAmt1 = nums[i] + robHelper(nums, i + 2); // include
    int robAmt2 = 0 + robHelper(nums, i + 1);       // exclude

    return max(robAmt1, robAmt2);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    int ans = robHelper(nums, 0);
    cout << ans << endl;
    return 0;
}