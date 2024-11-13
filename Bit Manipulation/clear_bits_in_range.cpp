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

int clearBitsInRange(int n, int i, int j)
{
    int a = (-1 << (i + 1));
    int b = (1 << j) - 1;
    int mask = a | b;
    n = n & mask;
    return n;
}

int main()
{
    int n = 15;
    printBits(n);
    int ans = clearBitsInRange(n, 2, 1);
    cout << "after clearing bits: " << ans << endl;
    printBits(ans);
    return 0;
}