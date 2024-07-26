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
// question: burning tree
// example:
// answer:
// explanation:
// tags:

Node *NoteToParentMapping(Node *root, unordered_map<Node *, Node *> &parentMap, int target)
{
    queue<Node *> q;
    Node *targetNode = 0;
    q.push(root);
    parentMap[root] = 0;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            targetNode = front;
        }

        if (front->left)
        {
            q.push(front->left);
            parentMap[front->left] = front;
        }
        if (front->right)
        {
            q.push(front->right);
            parentMap[front->right] = front;
        }
    }

    return targetNode;
}

int burnTheTree(Node *targetNode, unordered_map<Node *, Node *> &parentMap)
{
    unordered_map<Node *, bool> isBurnt;
    queue<Node *> q; // currently set on fire nodes

    int T = 0;
    q.push(targetNode);
    isBurnt[targetNode] = 1;

    while (!q.empty())
    {
        int size = q.size();
        bool isFireSpreaded = false;

        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !isBurnt[front->left])
            {
                q.push(front->left);
                isBurnt[front->left] = true;
                isFireSpreaded = true;
            }
            if (front->right && !isBurnt[front->right])
            {
                q.push(front->right);
                isBurnt[front->right] = true;
                isFireSpreaded = true;
            }
            if (parentMap[front] && !isBurnt[parentMap[front]])
            {
                q.push(parentMap[front]);
                isBurnt[parentMap[front]] = true;
                isFireSpreaded = true;
            }
        }
        if (isFireSpreaded)
        {
            ++T;
        }
    }

    return T;
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> parentMap;
    Node *tagetNode = NoteToParentMapping(root, parentMap, target);
    return burnTheTree(tagetNode, parentMap);
}