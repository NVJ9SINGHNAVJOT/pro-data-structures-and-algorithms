#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: all nodes till target sum
// example:
// answer:
// explanation:
// tags:

void solve(TreeNode *root, int targetSum, int &currSum, vector<int> &path, vector<vector<int>> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // Leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        // include curr node
        path.push_back(root->val);
        currSum += root->val;
        // check for target sum
        if (currSum == targetSum)
        {
            ans.push_back(path);
        }
        // exclude
        path.pop_back();
        currSum -= root->val;
        return;
    }

    // include curr node
    path.push_back(root->val);
    currSum += root->val;

    solve(root->left, targetSum, currSum, path, ans);
    solve(root->right, targetSum, currSum, path, ans);

    // backtrack
    path.pop_back();
    currSum -= root->val;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    int sum = 0;
    vector<int> temp;
    solve(root, targetSum, sum, temp, ans);
    return ans;
}