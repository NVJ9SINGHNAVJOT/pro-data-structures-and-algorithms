#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
using namespace std;

// algorithm:
// question: boundary traversal
// example:
// answer:
// explanation:
// tags:

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // Step 1:
    Node *root = new Node(data);

    // step 2:
    cout << "Enter data for left part of " << data << " node " << endl;
    root->left = buildTree();

    // step 3:
    cout << "Enter data for right part of " << data << " node " << endl;
    root->right = buildTree();

    return root;
}

void printLeftBoundary(Node *root)
{
    // base case
    // if root is NULL, then go back
    if (root == NULL)
        return;
    // if root is a leaf node , then go back
    if (root->left == NULL && root->right == NULL)
        return;

    cout << root->data << " ";

    if (root->left)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node *root)
{
    // base case
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node *root)
{
    // base case
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }

    cout << root->data << " ";
}

void boundaryTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    // A
    printLeftBoundary(root->left);
    // B
    printLeafBoundary(root);
    // C
    printRightBoundary(root->right);
}

int main()
{
    Node *root = NULL;

    root = buildTree();
    // nodes: 10 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 40 -1 100 -1 120 110 -1 -1 130 -1 -1

    boundaryTraversal(root);

    return 0;
}
