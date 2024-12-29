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

// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

const int mod = 1e9 + 7;

long solveMemo(vector<string> &words, string &target, int wi, int ti, vector<vector<int>> &dp, vector<vector<int>> &charFreq)
{
    if (ti >= target.size())
    {
        return 1;
    }
    if (wi >= words[0].size() || words[0].size() - wi < target.size() - ti)
    {
        return 0;
    }
    if (dp[wi][ti] != -1)
    {
        return dp[wi][ti];
    }

    long ans = 0;
    int targetCharIndex = target[ti] - 'a';

    // include
    if (charFreq[wi][targetCharIndex] > 0)
    {
        ans = (ans + (charFreq[wi][targetCharIndex] * solveMemo(words, target, wi + 1, ti + 1, dp, charFreq)) % mod) % mod;
    }

    // exclude
    ans = (ans + solveMemo(words, target, wi + 1, ti, dp, charFreq)) % mod;

    dp[wi][ti] = ans;
    return ans;
}

long solveTab(vector<string> &words, string &target, vector<vector<int>> &charFreq)
{
    vector<vector<long>> dp(words[0].size() + 1, vector<long>(target.size() + 1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][target.size()] = 1;
    }

    for (int wi = words[0].size() - 1; wi >= 0; wi--)
    {
        for (int ti = target.size() - 1; ti >= 0; ti--)
        {

            long ans = 0;
            int targetCharIndex = target[ti] - 'a';

            // include
            if (charFreq[wi][targetCharIndex] > 0)
            {
                ans = (ans + (charFreq[wi][targetCharIndex] * dp[wi + 1][ti + 1]) % mod) % mod;
            }

            // exclude
            ans = (ans + dp[wi + 1][ti]) % mod;

            dp[wi][ti] = ans;
        }
    }

    return dp[0][0];
}

int numWays(vector<string> &words, string target)
{
    vector<vector<int>> charFreq(words[0].size(), vector<int>(26, 0));
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[0].size(); j++)
        {
            int charIndex = words[i][j] - 'a';
            charFreq[j][charIndex]++;
        }
    }
    // charFreq is used as we need one char matching in wi index and total
    // number of count present at charFreq for wi index is number of ways it can be
    // used. So, we store frequency and as we cannot use previous index values
    // for a word in words.

    // vector<vector<int>> dp(words[0].size() + 1, vector<int>(target.size() + 1, -1));
    // int ans = solveMemo(words, target, 0, 0, dp, charFreq);

    int ans = solveTab(words, target, charFreq);
    return ans;
}

int main()
{
    vector<string> words = {"acca", "bbbb", "caca"};
    string target = "aba";
    cout << numWays(words, target) << endl;
    return 0;
}