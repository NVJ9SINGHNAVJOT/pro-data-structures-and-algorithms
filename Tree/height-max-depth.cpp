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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}

int main()
{
    Node *root = NULL;

    root = buildTree();
    // nodes: 20 30 50 -1 60 -1 -1 40 -1 -1 100 -1 -1

    cout << height(root) << endl;

    return 0;
}