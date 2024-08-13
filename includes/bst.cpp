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
#include <numeric>
#include "../includes/tree.cpp"
using namespace std;

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // check for data comparison with curr node data
    if (root->data > data)
    {
        // insert into left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}