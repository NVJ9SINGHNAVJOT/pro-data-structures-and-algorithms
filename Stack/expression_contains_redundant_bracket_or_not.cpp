#include <iostream>
#include <stack>
using namespace std;

// algorithm:
// question: expression contains redundant bracket or not
// example:
// answer:
// explanation:
// tags:

bool checkexpression(string &expression)
{
    stack<char> st;

    for (int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];
        // if opening bracket
        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            st.push(ch);
        }
        // if closing bracket
        else if (ch == ')')
        {
            if (!st.empty())
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '/' || temp == '*')
                {
                    while (temp == '+' || temp == '-' || temp == '/' || temp == '*')
                    {
                        st.pop();
                        temp = st.top();
                    }
                }
                else
                {
                    return false;
                }
                // after deleting all operators now check for opening bracket
                if (!st.empty())
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
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
        return true;
    }
    else
    {
        char temp = st.top();
        if (temp == '+' || temp == '-' || temp == '/' || temp == '*')
        {
            while (temp == '+' || temp == '-' || temp == '/' || temp == '*')
            {
                st.pop();
                if (!st.empty())
                {
                    temp = st.top();
                }
                else
                {
                    return true;
                }
            }
        }
        else
        {
            return false;
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string expresssion = "()(a/d+t)+(r+9-8)";

    if (checkexpression(expresssion))
    {
        cout << "expression is valid" << endl;
    }
    else
    {
        cout << "expression is not valid" << endl;
    }
    return 0;
}