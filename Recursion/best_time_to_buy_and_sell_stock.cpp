#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: best time to buy and sell stock
// example:
// answer:
// explanation:
// tags:

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int buyDay = prices[0];
    int sellDay = prices[0];

    for (int i = 0; i < prices.size(); i++)
    {
        if (buyDay > prices[i])
        {
            buyDay = prices[i];
            sellDay = prices[i];
        }
        if (sellDay < prices[i])
        {
            sellDay = prices[i];
        }
        profit = max(profit, sellDay - buyDay);
    }
    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int ans = maxProfit(prices);
    cout << ans << endl;
    return 0;
}
