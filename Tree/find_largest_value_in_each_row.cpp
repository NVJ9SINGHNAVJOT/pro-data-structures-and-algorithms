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
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> getValues(TreeNode *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    int maxi = INT_MIN;

    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front == nullptr)
        {
            ans.push_back(maxi);
            maxi = INT_MIN;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            maxi = max(maxi, front->val);
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }

    return ans;
}
vector<int> largestValues(TreeNode *root)
{
    return getValues(root);
}

int main()
{
    return 0;
}