#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

// algorithm:
// question: string to integer
// example:
// answer:
// explanation:
// tags:

int myAtoi(string s)
{
    int num = 0;
    int i = 0;
    int sign = 1; // Telling number is positive
    // Leading white spaces to be ignored
    while (s[i] == ' ')
    {
        i++;
    }
    // Check the sign of the number
    if (i < s.length() && (s[i] == '-' || s[i] == '+'))
    {
        if (s[i] == '-')
            sign = -1; // Telling number is negative
        i++;
    }
    // Checking the digits now
    while (i < s.length() && isdigit(s[i]))
    {
        if ((num > INT_MAX / 10) || (num == INT_MAX / 10 && s[i] >= '8'))
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num * sign;
}

int main()
{
    string s = "    -123hello125478";
    int ans = myAtoi(s);
    cout << ans << endl;
    return 0;
}