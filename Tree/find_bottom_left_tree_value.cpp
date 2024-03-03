#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;

// https://leetcode.com/problems/find-bottom-left-tree-value/description/

// algorithm:
// question: find bottom left tree value
// example:
// answer:
// explanation:
// tags:

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

class Solution
{
public:
    void findBottomLeftValueHelper(TreeNode *root, int i, int j, int &ans, pair<int, int> &p)
    {
        if (root == NULL)
        {
            return;
        }

        findBottomLeftValueHelper(root->left, i + 1, j - 1, ans, p);
        findBottomLeftValueHelper(root->right, i + 1, j + 1, ans, p);

        if (root->left == NULL && root->right == NULL)
        {
            if (j < p.second && i > p.first)
            {
                ans = root->val;
                p.first = i;
                p.second = j;
                return;
            }
            if (i > p.first)
            {
                ans = root->val;
                p.first = i;
                p.second = j;
                return;
            }
        }
    }

    int findBottomLeftValue(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return root->val;
        }
        int ans = 0;
        pair<int, int> p = {0, 0};
        findBottomLeftValueHelper(root, 0, 0, ans, p);
        return ans;
    }
};