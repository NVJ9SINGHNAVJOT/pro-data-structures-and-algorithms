#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                maxLen = max(len, maxLen);
            }
        }
    }
    return maxLen;
}

int main()
{
    string s = ")()())";
    int ans = longestValidParentheses(s);
    cout << ans << endl;
    return 0;
}