#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

int countRev(string s)
{
    // if odd sized string impossibel to make pairs
    if (s.size() & 1)
        return -1;

    int ans = 0;
    stack<char> st;

    for (auto ch : s)
    {
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    // if stack is not empty, let's count reversals
    while (!st.empty())
    {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if (a == b)
        {
            ans += 1;
        }
        else
        {
            ans += 2;
        }
    }

    return ans;
}

int main()
{
    string s = "}{{}}{{{";
    int ans = countRev(s);
    cout << ans << endl;
    return 0;
}