#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https -> link

// Definition for a data structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void bstToDllHelper(TreeNode *root, TreeNode *&head)
{
    if (root == nullptr)
    {
        return;
    }

    bstToDllHelper(root->right, head);

    if (head != nullptr)
    {
        head->left = root;
    }

    root->right = head;
    head = root;

    TreeNode *temp = root->left;
    root->left = nullptr;

    bstToDllHelper(temp, head);
}

TreeNode *bstToDll(TreeNode *root)
{
    TreeNode *head = nullptr;
    bstToDllHelper(root, head);
    return head;
}