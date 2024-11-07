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

int binExpPow(int n, int x)
{
    int ans = 1;
    while (x)
    {
        if (x & 1)
        {
            ans = ans * n;
        }
        n = n * n;
        x >>= 1;
    }
    return ans;
}

int main()
{
    cout << binExpPow(2, 6) << endl;
    return 0;
}