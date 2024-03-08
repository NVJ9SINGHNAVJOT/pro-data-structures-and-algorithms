#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// assuming there are only unique values in tree
bool findNodeInBST(Node *root, int target)
{
    /// base case
    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
        return true;
    // assuming there are only unique values in tree
    //  Node* leftAns = false;
    //  Node* rightAns = false;

    if (target > root->data)
    {
        // right subtree me search karo
        return findNodeInBST(root->right, target);
    }
    else
    {
        return findNodeInBST(root->left, target);
    }
}
