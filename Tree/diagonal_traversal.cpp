#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // use left element in q
        Node *temp = q.front();
        q.pop();

        // go to farmost right direction
        while (temp)
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}