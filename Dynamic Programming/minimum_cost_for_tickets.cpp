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

// https://leetcode.com/problems/minimum-cost-for-tickets/description/

int solveMemo(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
{
    // base
    if (i >= days.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    // 1 day pass taken
    int cost1 = costs[0] + solveMemo(days, costs, i + 1, dp);

    // 7 day pass taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost7 = costs[1] + solveMemo(days, costs, j, dp);

    // 30 day pass taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + solveMemo(days, costs, j, dp);

    // return minimun
    dp[i] = min(cost1, min(cost7, cost30));
    return dp[i];
}

int solveTab(vector<int> &days, vector<int> &costs)
{
    vector<int> dp(days.size() + 1, 0);

    for (int i = days.size() - 1; i >= 0; i--)
    {
        // 1 day pass taken
        int cost1 = costs[0] + dp[i + 1];

        // 7 day pass taken
        int passEndDay = days[i] + 7 - 1;
        int j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost7 = costs[1] + dp[j];

        // 30 day pass taken
        passEndDay = days[i] + 30 - 1;
        j = i;
        while (j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost30 = costs[2] + dp[j];
        ;

        // return minimun
        dp[i] = min(cost1, min(cost7, cost30));
    }

    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    // vector<int> dp(days.size() + 1, -1);
    // int ans = solveMemo(days, costs, 0, dp);
    int ans = solveTab(days, costs);

    return ans;
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    int ans = mincostTickets(days, costs);
    cout << ans << endl;
    return 0;
}