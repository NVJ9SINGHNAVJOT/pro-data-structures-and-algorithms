#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <list>
#include <unordered_set>
#include <numeric>
#include "../includes/tree.cpp"
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> sa, sb;
    Node *a = root1, *b = root2;

    while (a || b || !sa.empty() || !sb.empty())
    {
        while (a)
        {
            sa.push(a);
        }
        while (b)
        {
            sb.push(b);
        }
        if (sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data))
        {
            auto atop = sa.top();
            ans.push_back(atop->data);
            sa.pop();
            a = atop->right;
        }
        else
        {
            auto btop = sb.top();
            sb.pop();
            ans.push_back(btop->data);
            b = btop->right;
        }
    }
    return ans;
}