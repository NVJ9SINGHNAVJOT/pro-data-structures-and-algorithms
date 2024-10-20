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

// Definition of a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Count the number of nodes in the tree
int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if the tree is a complete binary tree
bool isComplete(TreeNode *root, int index, int &numNodes)
{
    if (root == nullptr)
        return true;
    if (index > numNodes)
        return false;
    return isComplete(root->left, 2 * index, numNodes) &&
           isComplete(root->right, 2 * index + 1, numNodes);
}

void isHeapHelper(TreeNode *root, bool &ans)
{
    // base case
    if (!ans)
    {
        return;
    }
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }

    // check for heap condition
    if (root->right == nullptr && root->data < root->left->data)
    {
        ans = false;
        return;
    }
    if ((root->right != nullptr) && ((root->data < root->left->data) || (root->data < root->right->data)))
    {
        ans = false;
        return;
    }

    isHeapHelper(root->left, ans);
    isHeapHelper(root->right, ans);
}

bool isHeap(TreeNode *tree)
{
    bool ans = true;
    int totalNodes = countNodes(tree);
    bool check = isComplete(tree, 1, totalNodes);
    if (!check)
    {
        return check;
    }
    isHeapHelper(tree, ans);
    return ans;
}