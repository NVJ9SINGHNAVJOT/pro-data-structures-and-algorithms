#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

string decodeString(string s)
{
    stack<string> st;
    for (auto ch : s)
    {
        if (ch == ']')
        {
            string stringToRepeat = "";
            while (!st.empty() && st.top() != "[")
            {
                string top = st.top();
                stringToRepeat += top;
                st.pop();
            }

            st.pop();

            // now number will be collected for repeating strings
            string numericTimes = "";
            while (!st.empty() && isdigit(st.top()[0]))
            {
                numericTimes += st.top();
                st.pop();
            }

            reverse(numericTimes.begin(), numericTimes.end());

            int n = stoi(numericTimes);

            // final decoding
            string currentDecode = "";
            while (n--)
            {
                currentDecode += stringToRepeat;
            }

            st.push(currentDecode);
        }
        else
        {
            string temp(1, ch);
            st.push(temp);
        }
    }

    string ans;

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "3[a2[c]]";
    string ans = decodeString(s);
    cout << ans << endl;
    s = "2[abc]3[cd]ef";
    ans = decodeString(s);
    cout << ans << endl;
    return 0;
}