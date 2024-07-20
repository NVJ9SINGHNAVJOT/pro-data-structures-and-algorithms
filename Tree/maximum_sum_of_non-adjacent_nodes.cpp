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
#include "../includes/tree.cpp"
using namespace std;

// algorithm:
// question: maximum sum of non-adjacent nodes
// example:
// answer:
// explanation:
// tags:

pair<int, int> getMaxSumHelper(Node *root)
{
    if (!root)
    {
        return {0, 0};
    }

    auto left = getMaxSumHelper(root->left);
    auto right = getMaxSumHelper(root->right);

    // sum including the node
    int a = root->data + left.second + right.second;

    // sum excluding the node
    int b = max(left.first, left.second) + max(right.first, right.second);

    return {a, b};
}

int getMaxSum(Node *root)
{
    auto ans = getMaxSumHelper(root);
    return max(ans.first, ans.second);
}