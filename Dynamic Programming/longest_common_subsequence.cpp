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

// https://leetcode.com/problems/longest-common-subsequence/description/

int solveRec(string &text1, string &text2, int i, int j)
{
    if (text1.length() == i || text2.length() == j)
    {
        return 0;
    }
    int ans = 0;
    if (text1[i] == text2[j])
    {
        ans = 1 + solveRec(text1, text2, i + 1, j + 1);
    }
    else
    {
        ans = 0 + max(solveRec(text1, text2, i + 1, j),
                      solveRec(text1, text2, i, j + 1));
    }

    return ans;
}

int solveMemo(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (text1.length() == i || text2.length() == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if (text1[i] == text2[j])
    {
        ans = 1 + solveMemo(text1, text2, i + 1, j + 1, dp);
    }
    else
    {
        ans = 0 + max(solveMemo(text1, text2, i + 1, j, dp),
                      solveMemo(text1, text2, i, j + 1, dp));
    }
    dp[i][j] = ans;
    return ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    int ans;
    // ans = solveRec(text1, text2, 0, 0);
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    ans = solveMemo(text1, text2, 0, 0, dp);
    return ans;
}
