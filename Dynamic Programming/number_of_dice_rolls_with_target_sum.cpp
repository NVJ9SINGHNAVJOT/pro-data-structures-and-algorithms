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
#include "../includes/vector.cpp"
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

long long int MOD = 1000000007;
long long int solveMemo(int n, int k, int target, vector<vector<long long int>> &dp)
{
    if (n == 0 && target == 0)
    {
        return 1;
    }
    if (n <= 0 || target <= 0)
    {
        return 0;
    }

    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    long long int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        long long int recAns = 0;
        recAns = solveMemo(n - 1, k, target - i, dp);
        ans = (ans % MOD + recAns % MOD) % MOD;
    }

    dp[n][target] = ans;

    return dp[n][target];
}

long long int solveTab(int n, int k, int target)
{
    vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, 0));

    // base case
    for (int i = 1; i <= k; i++)
    {
        if (i <= target - (n - 1))
        {
            dp[1][i] = 1;
        }
    }

    for (int index = 2; index <= n; index++)
    {
        for (int t = 1; t <= target; t++)
        {
            long long int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                long long int recAns = 0;
                if (t - i >= 0)
                {
                    recAns = dp[index - 1][t - i];
                }
                ans = (ans % MOD + recAns % MOD) % MOD;
            }
            dp[index][t] = ans;
        }
    }

    return dp[n][target];
}

long long int solveSpace(int n, int k, int target)
{
    vector<long long int> curr(target + 1, 0);

    // base case
    for (int i = 1; i <= k; i++)
    {
        if (i <= target - (n - 1))
        {
            curr[i] = 1;
        }
    }

    for (int index = 2; index <= n; index++)
    {
        for (int t = target; t >= 1; t--)
        {
            long long int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                long long int recAns = 0;
                if (t - i >= 0)
                {
                    recAns = curr[t - i];
                }
                ans = (ans % MOD + recAns % MOD) % MOD;
            }
            curr[t] = ans;
        }
    }

    return curr[target];
}

int numRollsToTarget(int n, int k, int target)
{
    // vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, -1));
    long long int ans = 0;
    // ans = solveMemo(n, k, target, dp);
    // ans = solveTab(n, k, target);
    ans = solveSpace(n, k, target);
    return ans;
}

int main()
{
    cout << numRollsToTarget(30, 30, 500) << endl;
    return 0;
}