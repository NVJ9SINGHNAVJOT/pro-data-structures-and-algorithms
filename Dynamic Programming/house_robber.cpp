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
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/house-robber/description/

int solveRec(vector<int> &nums, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }

    int include = solveRec(nums, n - 2) + nums[n];
    int exclude = solveRec(nums, n - 1) + 0;

    return max(include, exclude);
}

int solveMemo(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int include = solveMemo(nums, n - 2, dp) + nums[n];
    int exclude = solveMemo(nums, n - 1, dp) + 0;

    dp[n] = max(include, exclude);
    return dp[n];
}

int solveTab(vector<int> &nums)
{
    int n = nums.size() - 1;
    vector<int> dp(n + 1, -1);

    dp[0] = nums[0];

    for (int i = 1; i <= n; i++)
    {
        int include = 0;
        int exclude = 0;

        if (i - 2 >= 0)
        {
            include = dp[i - 2] + nums[i];
        }
        else
        {
            include = 0 + nums[i];
        }

        if (i - 1 >= 0)
        {
            exclude = dp[i - 1] + 0;
        }

        dp[i] = max(include, exclude);
    }

    return dp[n];
}

int solveSpace(vector<int> &nums)
{
    int n = nums.size() - 1;
    int prev2 = 0;
    int prev1 = nums[0];

    int curr = 0;

    for (int i = 1; i <= n; i++)
    {
        int include = 0;
        int exclude = 0;

        if (i - 2 >= 0)
        {
            include = prev2 + nums[i];
        }
        else
        {
            include = 0 + nums[i];
        }

        if (i - 1 >= 0)
        {
            exclude = prev1 + 0;
        }

        curr = max(include, exclude);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int rob(vector<int> &nums)
{
    int n = nums.size() - 1;
    // int ans = solveRec(nums, n);
    // vector<int> dp(n + 1, -1);
    // int ans = solveMemo(nums, n, dp);
    // int ans = solveTab(nums);
    int ans = solveSpace(nums);
    return ans;
}
