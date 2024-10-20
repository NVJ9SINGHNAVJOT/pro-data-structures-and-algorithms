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

void printBottomView(Node *root)
{
    if (root == NULL)
        return;

    /// create a map for storing hd(horizontal distance) -> topNode -> data
    map<int, int> topNode;

    // Level Order
    // we will store a pair consisting of Node and Horizontal Distance
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // jo bhi horizontal distance aaya h store answer for that hd
        // create entry
        topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    // ab aapka answer store hua hoga aapke map me
    cout << "Printing the answer: " << endl;
    for (auto i : topNode)
    {
        cout << i.first << " -> " << i.second << endl;
    }
}

int main()
{
    Node *root = NULL;

    root = buildTree();
    // nodes: 20 30 50 -1 60 -1 -1 40 -1 -1 100 -1 -1

    printBottomView(root);

    return 0;
}