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

int numRollsToTarget(int n, int k, int target)
{
    // base
    if (target < 0)
        return 0;
    if (n == 0 && target == 0)
        return 1;
    if (n == 0 && target != 0)
        return 0;
    if (n != 0 && target == 0)
        return 0;

    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans = ans + numRollsToTarget(n - 1, k, target - i);
    }

    return ans;
}

int main()
{
    int n = 2;
    int k = 6;
    int target = 7;
    int ans = numRollsToTarget(n, k, target);
    cout << ans << endl;
    return 0;
}
