#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm: include and exclude
// question: generate parentheses
// example:
// answer:
// explanation:
// tags:

void solve(vector<string> &ans, int open, int close, string output)
{
    // base case
    if (open == 0 && close == 0)
    {
        ans.push_back(output);
        return;
    }

    // include open bracket
    if (open > 0)
    {
        // output.push_back('(');
        solve(ans, open - 1, close, output + '(');
        // backtrack
        // output.pop_back();
    }

    // include close bracket
    if (open < close)
    {
        // output.push_back(')');
        solve(ans, open, close - 1, output + ')');
        // backtrack
        // output.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    int open = n;
    int close = n;
    string output = "";
    solve(ans, open, close, output);
    return ans;
}

int main()
{
    int n = 2;
    vector<string> ans = generateParenthesis(n);

    for (auto s : ans)
    {
        cout << s << endl;
    }
    cout << endl;

    return 0;
}