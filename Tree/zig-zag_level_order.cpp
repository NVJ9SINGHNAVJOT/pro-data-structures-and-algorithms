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
// question: zig-zag level order
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    bool LtoRDir = true;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int width = q.size();
        vector<int> oneLevel(width);

        for (int i = 0; i < width; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            int index = LtoRDir ? i : width - i - 1;
            oneLevel[index] = front->val;

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }

        // toggle the direction
        LtoRDir = !LtoRDir;
        ans.push_back(oneLevel);
    }

    return ans;
}