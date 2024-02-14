#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: minimum cost for tickets
// example:
// answer:
// explanation:
// tags:

int costTicketsHelper(vector<int> &days, vector<int> &costs, int i)
{
    // base
    if (i >= days.size())
    {
        return 0;
    }

    // sol for a case

    // 1 day pass taken
    int cost1 = costs[0] + costTicketsHelper(days, costs, i + 1);

    // 7 day pass taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost7 = costs[1] + costTicketsHelper(days, costs, j);

    // 30 day pass taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + costTicketsHelper(days, costs, j);

    // return minimun
    return min(cost1, min(cost7, cost30));
}

int minCostTickets(vector<int> &days, vector<int> &costs)
{
    return costTicketsHelper(days, costs, 0);
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    int ans = minCostTickets(days, costs);
    cout << ans << endl;
    return 0;
}