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

// https://leetcode.com/problems/count-ways-to-build-good-strings/description/

const int mod = 1e9 + 7;

int solveMemo(int &low, int &high, int &zero, int &one, int len, vector<int> &dp)
{
    if (len > high)
    {
        return 0;
    }
    if (dp[len] != -1)
    {
        return dp[len];
    }

    int ans = 0;
    // include current lenght
    if (len >= low && len <= high)
    {
        ans += 1;
    }

    ans += (solveMemo(low, high, zero, one, len + zero, dp) + solveMemo(low, high, zero, one, len + one, dp)) % mod;

    dp[len] = ans;
    return ans;
}

int solveTab(int &low, int &high, int &zero, int &one)
{
    vector<int> dp(high + 1, 0);

    for (int len = high; len >= 0; len--)
    {
        int ans = 0;

        // include current lenght
        if (len >= low && len <= high)
        {
            ans += 1;
        }

        if (len + zero <= high)
        {
            ans += dp[len + zero];
        }
        if (len + one <= high)
        {
            ans += dp[len + one];
        }

        ans %= mod;

        dp[len] = ans;
    }

    return dp[0];
}

int countGoodStrings(int low, int high, int zero, int one)
{
    // vector<int> dp(high + 1, -1);
    // int ans = solveMemo(low, high, zero, one, 0, dp);
    int ans = solveTab(low, high, zero, one);

    return ans;
}

int main()
{
    cout << countGoodStrings(200, 200, 10, 1) << endl;
    return 0;
}