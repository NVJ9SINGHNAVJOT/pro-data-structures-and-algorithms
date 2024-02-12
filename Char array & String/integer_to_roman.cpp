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
// question: integer to roman
// example:
// answer:
// explanation:
// tags:

string intToRoman(int num)
{
    string RomanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        // Going from largest to smallest
        while (num >= values[i])
        {
            ans += RomanSymbols[i];
            num -= values[i];
        }
    }
    return ans;
}

int main()
{
    int num = 1994;
    string ans = intToRoman(num);
    cout << ans << endl;
}
