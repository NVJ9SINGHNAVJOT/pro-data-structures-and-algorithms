#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: longest common prefix
// example:
// answer:
// explanation:
// tags:

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    int i = 0;
    while (true)
    {
        char curr = 0;
        for (auto str : strs)
        {
            // Checking for out of bound
            if (i >= str.size())
            {
                curr = 0;
                break;
            }
            if (curr == 0)
                curr = str[i];
            else if (str[i] != curr)
            {
                // curr is set to 0 for getting out of infinite loop
                curr = 0;
                break;
            }
        }

        if (curr == 0)
        {
            break;
        }
        ans.push_back(curr);
        i++;
    }
    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    string ans = longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}