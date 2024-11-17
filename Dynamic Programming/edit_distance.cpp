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

// https://leetcode.com/problems/edit-distance/description/

int solveRec(string &word1, string &word2, int i, int j)
{
    if (i == word1.length())
    {
        return word2.length() - j;
    }
    if (j == word2.length())
    {
        return word1.length() - i;
    }

    int ans = 0;
    if (word1[i] == word2[j])
    {
        ans = solveRec(word1, word2, i + 1, j + 1);
    }
    else
    {
        int insert = 1 + solveRec(word1, word2, i, j + 1);
        int deleted = 1 + solveRec(word1, word2, i + 1, j);
        int replace = 1 + solveRec(word1, word2, i + 1, j + 1);
        ans = min(insert, min(deleted, replace));
    }

    return ans;
}

int solveMemo(string &w1, string &w2, int i, int j, vector<vector<int>> &dp)
{
    if (i == w1.length())
    {
        return w2.length() - j;
    }
    if (j == w2.length())
    {
        return w1.length() - i;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    if (w1[i] == w2[j])
    {
        ans = solveMemo(w1, w2, i + 1, j + 1, dp);
    }
    else
    {
        int insert = 1 + solveMemo(w1, w2, i, j + 1, dp);
        int deleted = 1 + solveMemo(w1, w2, i + 1, j, dp);
        int replace = 1 + solveMemo(w1, w2, i + 1, j + 1, dp);
        ans = min(insert, min(deleted, replace));
    }

    dp[i][j] = ans;
    return ans;
}

int solveTab(string &w1, string &w2)
{
    vector<vector<int>> dp(w1.length() + 1, vector<int>(w2.length() + 1, -1));

    for (int i = 0; i <= w1.length(); i++)
    {
        dp[i][w2.length()] = w1.length() - i;
    }
    for (int j = 0; j <= w2.length(); j++)
    {
        dp[w1.length()][j] = w2.length() - j;
    }

    for (int i = w1.length() - 1; i >= 0; i--)
    {
        for (int j = w2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (w1[i] == w2[j])
            {
                ans = dp[i + 1][j + 1];
            }
            else
            {
                int insert = 1 + dp[i][j + 1];
                int deleted = 1 + dp[i + 1][j];
                int replace = 1 + dp[i + 1][j + 1];
                ans = min(insert, min(deleted, replace));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int solveSpace(string &w1, string &w2)
{
    vector<int> curr(w2.length() + 1, 0);
    vector<int> next(w2.length() + 1, 0);

    for (int j = 0; j <= w2.length(); j++)
    {
        next[j] = w2.length() - j;
    }

    for (int i = w1.length() - 1; i >= 0; i--)
    {
        curr[w2.length()] = w1.length() - i;
        for (int j = w2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (w1[i] == w2[j])
            {
                ans = next[j + 1];
            }
            else
            {
                int insert = 1 + curr[j + 1];
                int deleted = 1 + next[j];
                int replace = 1 + next[j + 1];
                ans = min(insert, min(deleted, replace));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return curr[0];
}

int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
    {
        return word2.length();
    }
    if (word2.length() == 0)
    {
        return word1.length();
    }
    int ans;
    // ans = solveRec(word1, word2, 0, 0);
    vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
    // ans = solveMemo(word1, word2, 0, 0, dp);
    // ans = solveTab(word1, word2);
    ans = solveSpace(word1, word2);

    return ans;
}