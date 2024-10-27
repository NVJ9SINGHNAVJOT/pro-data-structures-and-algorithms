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

int countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        int lastBit = n & 1;
        if (lastBit)
            count++;
        // right shift
        n = n >> 1;
    }
    return count;
}

int countSetBits2(int n)
{
    int count = 0;
    while (n != 0)
    {
        // remove last set bit
        n = (n & (n - 1));
        count++;
    }
    return count;
}

int main()
{

    int n = 10;

    int ans = countSetBits(n);
    cout << ans << endl;
    ans = countSetBits2(n);
    cout << ans << endl;

    return 0;
}