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

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

int solveMemo(vector<int> &prices, int i, int buy, int limit, vector<vector<vector<int>>> &dp)
{
    if (i >= prices.size() || limit == 0)
        return 0;
    if (dp[i][buy][limit] != -1)
    {
        return dp[i][buy][limit];
    }
    int profit = 0;
    if (buy)
    {
        int buyItProfit = -prices[i] + solveMemo(prices, i + 1, 0, limit, dp);
        int skipProfit = solveMemo(prices, i + 1, 1, limit, dp);
        profit = max(buyItProfit, skipProfit);
    }
    else
    {
        int sellItProfit = prices[i] + solveMemo(prices, i + 1, 1, limit - 1, dp);
        int skipProfit = solveMemo(prices, i + 1, 0, limit, dp);
        profit = max(sellItProfit, skipProfit);
    }
    dp[i][buy][limit] = profit;
    return profit;
}

int solveTab(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
            {

                int profit = 0;
                if (buy)
                {
                    int buyItProfit = -prices[i] + dp[i + 1][0][limit];
                    int skipProfit = dp[i + 1][1][limit];
                    profit = max(buyItProfit, skipProfit);
                }
                else
                {
                    int sellItProfit = prices[i] + dp[i + 1][1][limit - 1];
                    int skipProfit = dp[i + 1][0][limit];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[i][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int solveSpace(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3, 0)));
    // dp[1] is next
    // dp[0] is curr
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int limit = 1; limit < 3; limit++)
            {

                int profit = 0;
                if (buy)
                {
                    int buyItProfit = -prices[i] + dp[1][0][limit];
                    int skipProfit = dp[1][1][limit];
                    profit = max(buyItProfit, skipProfit);
                }
                else
                {
                    int sellItProfit = prices[i] + dp[1][1][limit - 1];
                    int skipProfit = dp[1][0][limit];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[0][buy][limit] = profit;
            }
        }
        dp[1] = dp[0];
    }
    return dp[0][1][2];
}

int maxProfit(vector<int> &prices)
{
    // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    // int ans = solveMemo(prices, 0, 1, 2, dp);
    // int ans = solveTab(prices);
    int ans = solveSpace(prices);

    return ans;
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
    return 0;
}