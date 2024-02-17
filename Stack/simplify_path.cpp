#include <iostream>
#include <stack>
using namespace std;

// algorithm:
// question: simplify path
// example:
// answer:
// explanation:
// tags:

void reverseStack(stack<string> &s, string &ans)
{
    while (!s.empty())
    {
        ans = s.top() + ans;
        s.pop();
    }
}

string simplifyPath(string path)
{
    stack<string> s;
    int i = 0;

    while (i < path.size())
    {
        int start = i;
        int end = i + 1;

        while (end < path.size() && path[end] != '/')
        {
            ++end;
        }

        string minPath = path.substr(start, end - start);
        i = end;

        if (minPath == "/" || minPath == "/.")
        {
            continue;
        }

        if (minPath != "/..")
        {
            s.push(minPath);
        }
        else if (!s.empty())
        {
            s.pop();
        }
    }

    string ans = s.empty() ? "/" : "";
    reverseStack(s, ans);

    return ans;
}

int main()
{
    string path = "/home/../foo/";
    string ans = simplifyPath(path);
    cout << ans << endl;
    return 0;
}