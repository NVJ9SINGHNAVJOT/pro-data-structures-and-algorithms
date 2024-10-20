#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm: binary search
// example:
// answer:
// explanation:
// tags:

bool isPossible(vector<int> &stalls, int n, int k, int solution)
{
    int cowCount = 1;
    int pos = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - pos >= solution)
        {
            cowCount++;
            pos = stalls[i];
        }
        if (cowCount == k)
            return true;
    }
    return false;
}

int cowDistance(int n, int k, vector<int> &stalls)
{
    // Sort the stalls as we need to apply binary search algorithm
    sort(stalls.begin(), stalls.end());
    // Defining search space
    int start = 0;
    int end = stalls[n - 1] - stalls[0];
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(stalls, n, k, mid))
        {
            // Store it
            ans = mid;
            // Go ahead to get maximum possible solution
            start = mid + 1;
        }
        else
        {
            // Go behind
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    int k = 3;
    vector<int> stalls{1, 2, 4, 8, 9};
    int ans = cowDistance(n, k, stalls);
    cout << ans << endl;
    return 0;
}
