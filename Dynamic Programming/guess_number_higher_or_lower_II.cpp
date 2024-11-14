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

// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

int solveRec(int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveRec(start, i - 1), solveRec(i + 1, end)));
    }

    return ans;
}

int solveMemo(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveRec(start, i - 1), solveRec(i + 1, end)));
    }
    dp[start][end] = ans;

    return ans;
}

int getMoneyAmount(int n)
{
    int ans;
    // ans = solveRec(1, n);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    ans = solveMemo(1, n, dp);
    return ans;
}

int main()
{
    getMoneyAmount(10);
    return 0;
}