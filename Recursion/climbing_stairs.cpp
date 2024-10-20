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

int climbStairs(int n)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        // 1 way to reach 0th and 1st stair
        return 1;
    }
    // Recursive Relation
    int ans = climbStairs(n - 1) + climbStairs(n - 2);
    return ans;
}
int main()
{
    int n = 15;
    int ways = climbStairs(n);
    cout << "Total ways to reach the " << n << " stair is " << ways << endl;
    return 0;
}