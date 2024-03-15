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
// question: longest bst in a binary tree
// example:
// answer:
// explanation:
// tags:

// https -> link

// Definition for a val structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class NodeData
{
public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData()
    {
    }
    NodeData(int size, int max, int min, bool valid)
    {
        this->size = size;
        this->minVal = min;
        this->maxVal = max;
        this->validBST = valid;
    }
};

NodeData *findLargestBSTHelper(TreeNode *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        NodeData *temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData *leftKaAns = findLargestBSTHelper(root->left, ans);
    NodeData *rightKaAns = findLargestBSTHelper(root->right, ans);

    // checking starts here
    NodeData *currNodeKaAns = new NodeData();

    currNodeKaAns->size = leftKaAns->size + rightKaAns->size + 1;
    currNodeKaAns->maxVal = max(root->val, rightKaAns->maxVal);
    currNodeKaAns->minVal = min(root->val, leftKaAns->minVal);

    // check for valid bst
    if (leftKaAns->validBST && rightKaAns->validBST && (root->val > leftKaAns->maxVal && root->val < rightKaAns->minVal))
    {
        currNodeKaAns->validBST = true;
    }
    else
    {
        currNodeKaAns->validBST = false;
    }

    if (currNodeKaAns->validBST)
    {
        ans = max(ans, currNodeKaAns->size);
    }
    return currNodeKaAns;
}

int largestBst(TreeNode *root)
{
    int ans = 0;
    findLargestBSTHelper(root, ans);
    return ans;
}