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
#include "../includes/bits.cpp"
using namespace std;

int getIthBit(int n, int i)
{
    int mask = 1 << i;
    printBits(mask);
    int ans = n & mask;
    printBits(ans);

    // If ans is zero then nth bit is 0, else some other non-zero value means bit is 1
    if (ans == 0)
        return 0;
    else
        return 1;
}

int main()
{
    int n = 10;
    int ans = getIthBit(n, 3);

    cout << ans << endl;

    return 0;
}