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

int main()
{
    int n = 50;

    cout << (n & 1) << endl;

    if (n & 1)
    {
        cout << "n is odd" << endl;
    }
    else
    {
        cout << "n is even" << endl;
    }
    return 0;
}