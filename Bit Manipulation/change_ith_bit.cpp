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

// set ith bit to 1
int setIthBit(int n, int i)
{
    int mask = 1 << i;
    return n | mask;
}

// set ith bit to 0
int clearIthBit(int n, int i)
{
    int mask = ~(1 << i);
    return n & mask;
}

int updateIthBit(int n, int i, int target)
{
    if (target == 0)
    {
        return clearIthBit(n, i);
    }

    return setIthBit(n, i);
}

int main()
{
    int n = 10;
    int ans = setIthBit(n, 2);

    cout << ans << endl;

    ans = clearIthBit(n, 1);

    cout << ans << endl;

    ans = updateIthBit(n, 9, 1);

    cout << ans << endl;

    return 0;
}