#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: diameter of binary tree
// example:
// answer:
// explanation:
// tags:

int diameterHelper(TreeNode *root, int &dia)
{
    if (root == NULL)
        return 0;

    int leftHeight = diameterHelper(root->left, dia);
    int rightHeight = diameterHelper(root->right, dia);

    dia = max(dia, leftHeight + rightHeight);

    int ans = max(leftHeight, rightHeight) + 1;

    return ans;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int dia = 0;
    diameterHelper(root, dia);
    return dia;
}
