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
// example:
// answer:
// explanation:
// tags:

void inorder(Node *root, Node *&prev)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inorder(root->right, prev);
}

Node *flatten(Node *root)
{
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    inorder(root, prev);
    prev->left = prev->right = NULL;
    root = dummy->right;
    return root;
}