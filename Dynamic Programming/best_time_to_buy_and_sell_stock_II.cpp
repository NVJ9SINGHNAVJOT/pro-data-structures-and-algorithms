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

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

int solveRec(vector<int> &prices, int i, int buy)
{
    if (i >= prices.size())
        return 0;

    int profit = 0;
    if (buy)
    {
        int buyItProfit = -prices[i] + solveRec(prices, i + 1, 0);
        int skipProfit = solveRec(prices, i + 1, 1);
        profit = max(buyItProfit, skipProfit);
    }
    else
    {
        int sellItProfit = prices[i] + solveRec(prices, i + 1, 1);
        int skipProfit = solveRec(prices, i + 1, 0);
        profit = max(sellItProfit, skipProfit);
    }

    return profit;
}

int solveMemo(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
{
    if (i >= prices.size())
        return 0;
    if (dp[i][buy] != -1)
    {
        return dp[i][buy];
    }
    int profit = 0;
    if (buy)
    {
        int buyItProfit = -prices[i] + solveMemo(prices, i + 1, 0, dp);
        int skipProfit = solveMemo(prices, i + 1, 1, dp);
        profit = max(buyItProfit, skipProfit);
    }
    else
    {
        int sellItProfit = prices[i] + solveMemo(prices, i + 1, 1, dp);
        int skipProfit = solveMemo(prices, i + 1, 0, dp);
        profit = max(sellItProfit, skipProfit);
    }
    dp[i][buy] = profit;
    return profit;
}

int solveTab(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyItProfit = -prices[i] + dp[i + 1][0];
                int skipProfit = dp[i + 1][1];
                profit = max(buyItProfit, skipProfit);
            }
            else
            {
                int sellItProfit = prices[i] + dp[i + 1][1];
                int skipProfit = dp[i + 1][0];
                profit = max(sellItProfit, skipProfit);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}

int solveSpace(vector<int> &prices)
{
    vector<int> curr(2, 0);
    vector<int> next(2, 0);
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if (buy)
            {
                int buyItProfit = -prices[i] + next[0];
                int skipProfit = next[1];
                profit = max(buyItProfit, skipProfit);
            }
            else
            {
                int sellItProfit = prices[i] + next[1];
                int skipProfit = next[0];
                profit = max(sellItProfit, skipProfit);
            }
            curr[buy] = profit;
        }
        next = curr;
    }
    return curr[1];
}

int maxProfit(vector<int> &prices)
{
    // int ans = solveRec(prices, 0, 1);
    // vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    // int ans = solveMemo(prices, 0, 1, dp);
    // int ans = solveTab(prices);
    int ans = solveSpace(prices);

    return ans;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}