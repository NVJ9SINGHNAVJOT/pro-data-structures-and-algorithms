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
// question: kth samllest element in bst
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// Definition for a data structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void kthSmallestHelper(TreeNode *root, int &k, int &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (k == -1)
    {
        return;
    }

    kthSmallestHelper(root->left, k, ans);
    k--;

    if (k == 0)
    {
        ans = root->val;
        k = -1;
    }

    kthSmallestHelper(root->right, k, ans);
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = -1;
    kthSmallestHelper(root, k, ans);
    return ans;
}