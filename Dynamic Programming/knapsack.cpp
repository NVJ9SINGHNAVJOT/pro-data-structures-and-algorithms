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

int solveRec(int weight[], int value[], int index, int capacity)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    // include and exclude
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveRec(weight, value, index - 1, capacity - weight[index]);
    }

    int exclude = 0 + solveRec(weight, value, index - 1, capacity);

    int ans = max(include, exclude);

    return ans;
}

int solveMemo(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // include and exclude
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveMemo(weight, value, index - 1, capacity - weight[index], dp);
    }

    int exclude = 0 + solveMemo(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int solveTab(int weight[], int value[], int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + dp[index - 1][wt - weight[index]];
            }
            int exclude = 0 + dp[index - 1][wt];

            dp[index][wt] = max(include, exclude);
        }
    }

    return dp[n - 1][capacity];
}

int solveSpace(int weight[], int value[], int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + prev[wt - weight[index]];
            }
            int exclude = 0 + prev[wt];

            curr[wt] = max(include, exclude);
        }

        prev = curr;
    }

    return curr[capacity];
}

int solveSpace2(int weight[], int value[], int n, int capacity)
{
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >= 0; wt--)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + curr[wt - weight[index]];
            }
            int exclude = 0 + curr[wt];

            curr[wt] = max(include, exclude);
        }
    }

    return curr[capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int capacity = 4;
    int n = sizeof(weight) / sizeof(int);

    int ans;

    // ans = solveRec(weight, value, n - 1, capacity);

    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // ans = solveMemo(weight, value, n - 1, capacity, dp);

    // ans = solveTab(weight, value, n, capacity);

    // ans = solveSpace(weight, value, n, capacity);

    ans = solveSpace2(weight, value, n, capacity);

    cout << ans << endl;

    return 0;
}