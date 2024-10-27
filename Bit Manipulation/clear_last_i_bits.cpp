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

int clearLastIBits(int n, int i)
{
    int mask = (-1 << i);
    return n & mask;
}

int main()
{
    int n = 7;
    int ans = clearLastIBits(n, 2);

    cout << ans << endl;

    return 0;
}
