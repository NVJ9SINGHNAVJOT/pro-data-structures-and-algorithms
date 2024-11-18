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
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/longest-increasing-subsequence/description/

int solveRec(vector<int> &arr, int prev, int curr)
{
    if (curr >= arr.size())
    {
        return 0;
    }

    // include
    int include = 0;
    if (prev == -1 || arr[prev] < arr[curr])
        include = 1 + solveRec(arr, curr, curr + 1);

    // excude
    int exclude = 0 + solveRec(arr, prev, curr + 1);

    int ans = max(include, exclude);

    return ans;
}

int solveMemo(vector<int> &arr, int prev, int curr, vector<vector<int>> &dp)
{
    if (curr >= arr.size())
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }

    // include
    int include = 0;
    if (prev == -1 || arr[prev] < arr[curr])
        include = 1 + solveMemo(arr, curr, curr + 1, dp);

    // excude
    int exclude = 0 + solveMemo(arr, prev, curr + 1, dp);

    int ans = max(include, exclude);
    dp[curr][prev + 1] = ans;

    return ans;
}

int solveTab(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || arr[prev] < arr[curr])
            {
                include = 1 + dp[curr + 1][curr + 1];
            }

            int exclude = 0;
            exclude = 0 + dp[curr + 1][prev + 1];

            int ans = max(include, exclude);

            dp[curr][prev + 1] = ans;
        }
    }
    return dp[0][0];
}

int solveSpace(vector<int> &arr)
{
    int n = arr.size();
    vector<int> current(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || arr[prev] < arr[curr])
            {
                include = 1 + next[curr + 1];
            }

            int exclude = 0 + next[prev + 1];

            int ans = max(include, exclude);

            current[prev + 1] = ans;
        }
        next = current;
    }
    return current[0];
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int ans;
    // ans = solveRec(nums, -1, 0);
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // ans = solveMemo(nums, -1, 0, dp);
    // ans = solveTab(nums);
    ans = solveSpace(nums);

    return ans;
}