#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;

// algorithm:
// question: morris traversal
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
        // left node is null, then visit and go right
        if (curr->left == nullptr)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        // left node is not null
        else
        {
            // find inorder predecessor
            TreeNode *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }

            // if pred right node is null, then go left after establishing link from pred to curr
            if (pred->right == nullptr)
            {
                pred->right = curr;
                curr = curr->left;
            }
            // left is already visited, go right after visiting curr node while removing the link
            else
            {
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}