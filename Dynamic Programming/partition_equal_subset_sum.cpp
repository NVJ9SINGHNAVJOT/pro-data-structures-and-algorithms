#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <list>
#include <unordered_set>
#include <numeric>
using namespace std;

// algorithm:
// question: partition equal subset sum
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/partition-equal-subset-sum/description/

bool solveRec(int index, vector<int> &nums, int target)
{
    // base case
    int n = nums.size();
    if (index >= n)
    {
        return 0;
    }

    if (target < 0)
    {
        return 0;
    }

    if (target == 0)
    {
        return 1;
    }

    bool include = solveRec(index + 1, nums, target - nums[index]);
    bool exclude = solveRec(index + 1, nums, target);

    return (include || exclude);
}

bool sovleMemo(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    // base case
    int n = nums.size();
    if (index >= n)
    {
        return 0;
    }
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool include = sovleMemo(index + 1, nums, target - nums[index], dp);
    bool exclude = sovleMemo(index + 1, nums, target, dp);

    dp[index][target] = (include || exclude);

    return dp[index][target];
}

bool solveTab(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));

    // base condition
    if (target >= nums[0])
    {
        dp[0][nums[0]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
            {
                include = dp[index - 1][t - nums[index]];
            }

            bool exclude = dp[index - 1][t];

            dp[index][t] = (include || exclude);
        }
    }

    return dp[n - 1][target];
}

bool solveSpace(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> curr(target + 1, 0);

    // base condition
    if (target >= nums[0])
    {
        curr[nums[0]] = 1;
    }
    curr[0] = 1;

    for (int index = 1; index < n; index++)
    {
        for (int t = target; t >= 0; t--)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
            {
                include = curr[t - nums[index]];
            }

            bool exclude = curr[t];

            curr[t] = (include || exclude);
        }
    }

    return curr[target];
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    if (sum & 1)
    {
        return false;
    }

    int target = sum / 2;
    int index = 0;
    bool ans;

    // ans = solveRec(index, nums, target);

    // vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
    // ans = sovleMemo(index, nums, target, dp);

    // ans = solveTab(nums, target);

    ans = solveSpace(nums, target);
    return ans;
}