#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: max sum of non-adjacent elements
// example:
// answer:
// explanation:
// tags:

void solveRec(vector<int> &arr, int sum, int &maxi, int i)
{
    // Base Case
    if (i >= arr.size())
    {
        maxi = max(sum, maxi);
        return;
    }
    // include
    solveRec(arr, sum + arr[i], maxi, i + 2);
    // exclude
    solveRec(arr, sum, maxi, i + 1);
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    solveRec(arr, sum, maxi, i);
    cout << maxi;
    return 0;
}