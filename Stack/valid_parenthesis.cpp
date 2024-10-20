#include <iostream>
#include <stack>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

bool isValid(string s)
{

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // opening bracket
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // closing bracket - ch
            if (!st.empty())
            {
                char topCh = st.top();
                if (ch == ')' && topCh == '(')
                {
                    // matching brackets
                    st.pop();
                }
                else if (ch == '}' && topCh == '{')
                {
                    // matching brackets
                    st.pop();
                }
                else if (ch == ']' && topCh == '[')
                {
                    // matching brackets
                    st.pop();
                }
                else
                {
                    // brackets not matching
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        // valid
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "(){}[]";
    bool ans = isValid(s);
    cout << ans << endl;
    return 0;
}