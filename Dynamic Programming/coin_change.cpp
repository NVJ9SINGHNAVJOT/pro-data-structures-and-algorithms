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

// https://leetcode.com/problems/coin-change/description/

int solveMemo(vector<int> &coins, int amount, vector<int> &dp)
{
    // base case
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }
    // memo
    if (dp[amount] != -1)
    {
        return dp[amount];
    }

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveMemo(coins, amount - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return dp[amount] = mini;
}

int solveTab(vector<int> &coins, int amount)
{
    // create dp
    vector<int> dp(amount + 1, INT_MAX);
    // base case
    dp[0] = 0;

    for (int target = 1; target <= amount; target++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (target - coins[i] >= 0)
            {
                int ans = dp[target - coins[i]];
                if (ans != INT_MAX)
                {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        dp[target] = mini;
    }

    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    // vector<int> dp(amount + 1, -1);
    // int ans = solveMemo(coins, amount, dp);

    int ans = solveTab(coins, amount);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}