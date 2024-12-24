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

// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

bool check(vector<int> &a, vector<int> &b)
{
    if (b[0] >= a[0] && b[1] >= a[1] && b[2] >= a[2])
        return true;
    else
        return false;
}

int solveMemo(int prev, int curr, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (curr >= arr.size())
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }

    int include = 0;
    if (prev == -1 || check(arr[prev], arr[curr]))
    {
        include = arr[curr][2] + solveMemo(curr, curr + 1, arr, dp);
    }
    int exclude = solveMemo(prev, curr + 1, arr, dp);

    int ans = max(include, exclude);

    dp[curr][prev + 1] = ans;
    return ans;
}

int solveTab(vector<vector<int>> &arr)
{
    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, 0));
    int n = arr.size();
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(arr[prev], arr[curr]))
            {
                include = arr[curr][2] + dp[curr + 1][curr + 1];
            }
            int exclude = dp[curr + 1][prev + 1];
            int ans = max(include, exclude);
            dp[curr][prev + 1] = ans;
        }
    }
    return dp[0][0];
}

int solveSpace(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(arr[prev], arr[curr]))
            {
                include = arr[curr][2] + currRow[curr + 1];
            }
            int exclude = nextRow[prev + 1];
            int ans = max(include, exclude);
            currRow[prev + 1] = ans;
        }
        nextRow = currRow;
    }
    return currRow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    // sort every array
    for (auto &a : cuboids)
    {
        sort(a.begin(), a.end());
    }

    // sort the 2D array
    sort(cuboids.begin(), cuboids.end());

    // apply lis logic
    // vector<vector<int>> dp(cuboids.size() + 1, vector<int>(cuboids.size() + 1, -1));
    // int ans = solveMemo(-1, 0, cuboids, dp);
    // int ans = solveTab(cuboids);
    int ans = solveSpace(cuboids);
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}};
    cout << maxHeight(matrix) << endl;
    return 0;
}