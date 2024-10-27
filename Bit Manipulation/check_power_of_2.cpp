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
#include <iostream>
#include <bitset>
using namespace std;

bool checkPowerOf2(int n)
{
    if ((n & (n - 1)) == 0)
        return true;
    else
        return false;
}

int main()
{
    int n = 8;
    int ans = checkPowerOf2(n);

    cout << ans << endl;

    return 0;
}