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

int solveOptimal(vector<int> &arr)
{
    int n = arr.size();

    if (n == 0)
    {
        return 0;
    }

    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }

    return ans.size();
}

int main()
{
    vector<int> arr = {5, 8, 3, 2, 1, 9, 7};

    cout << solveOptimal(arr);

    return 0;
}