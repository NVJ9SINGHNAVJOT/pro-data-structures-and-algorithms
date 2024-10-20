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
#include "../includes/tree.cpp"
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

void solve(Node *root, unordered_map<int, bool> &visited, bool &ans)
{
    if (root == 0)
    {
        return;
    }
    // visit the node
    visited[root->data] = 1;

    if (root->left == 0 && root->right == 0)
    {
        // last node
        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;

        if (visited.find(xp1) != visited.end() &&
            visited.find(xm1) != visited.end())
        {
            ans = true;
            return;
        }
    }

    solve(root->left, visited, ans);
    solve(root->right, visited, ans);
}

bool isDeadEnd(Node *root)
{
    bool ans = false;
    unordered_map<int, bool> visited;
    solve(root, visited, ans);
    return ans;
}