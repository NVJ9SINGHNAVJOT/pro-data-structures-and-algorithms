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

// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

int solveRec(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    // base case
    if (left == right)
        return 0;

    int ans = INT_MAX;

    for (int i = left; i < right; i++)
    {
        ans = min(ans,
                  maxi[{left, i}] * maxi[{i + 1, right}] + solveRec(arr, maxi, left, i) + solveRec(arr, maxi, i + 1, right));
    }
    return ans;
}

int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
        }
    }
    int n = arr.size();
    int ans = solveRec(arr, maxi, 0, n - 1);

    return ans;
}