#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // base case
    if (root == NULL)
        return NULL;

    // check for p and q;
    if (root->val == p->val)
        return p;
    if (root->val == q->val)
        return q;

    // check with left and right nodes
    TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns == NULL && rightAns == NULL)
    {
        return NULL;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return root;
    }
}