#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

int solveRec(vector<int> arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solveRec(arr, n - arr[i]);
        maxi = max(maxi, ans + 1);
    }

    return maxi;
}

int main()
{
    vector<int> arr{3, 3, 3};
    int n = 8;

    int ans = solveRec(arr, n);
    if (ans < 0)
    {
        ans = ans + INT_MAX;
    }
    cout << ans << endl;
    return 0;
}