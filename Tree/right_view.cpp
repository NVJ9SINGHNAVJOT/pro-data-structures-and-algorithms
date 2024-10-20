#include <iostream>
#include <queue>
using namespace std;

// algorithm:
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

void printRightView(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    // right
    printRightView(root->right, ans, level + 1);

    // left
    printRightView(root->left, ans, level + 1);
}

int main()
{
    Node *root = NULL;

    root = buildTree();
    // nodes: 20 30 50 -1 60 -1 -1 40 -1 -1 100 -1 -1

    vector<int> ans;
    printRightView(root, ans, 0);

    for (auto n : ans)
    {
        cout << n << endl;
    }
    cout << endl;

    return 0;
}