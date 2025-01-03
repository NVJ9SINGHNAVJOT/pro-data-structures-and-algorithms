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

int maxLen(vector<int> &A, int n)
{
    unordered_map<int, int> map;
    int csum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        // if (A[i] == 0)
        // {
        //     A[i] = -1;
        // }

        csum += A[i];
        if (csum == 0)
        {
            ans = max(ans, i + 1);
        }
        else if (map.find(csum) == map.end())
        {
            map[csum] = i;
        }
        else
        {
            ans = max(ans, i - map[csum]);
        }
    }

    return ans;
}

int main()
{
    vector<int> a = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLen(a, a.size()) << endl;
    return 0;
}