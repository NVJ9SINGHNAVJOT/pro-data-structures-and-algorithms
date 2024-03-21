#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

// algorithm:
// question: inorder predecessor in bst
// example:
// answer:
// explanation:
// tags:

// https -> link

// Definition for a data structure
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

Node *findPredecessor(Node *root, Node *p)
{
    Node *pred = 0;
    Node *curr = root;
    while (curr)
    {
        if (curr->data < p->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    return pred;
}