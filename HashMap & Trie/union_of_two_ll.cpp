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
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

struct Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        // If the node points to another node, delete it recursively
        if (this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }

        cout << "Node with value: " << this->data << " deleted" << endl;
    }
};

struct Node *makeUnion(struct Node *head1, struct Node *head2)
{
    map<int, Node *> map;
    Node *curr = head1;

    // L1 hashed
    while (curr)
    {
        map[curr->data] = curr;
        curr = curr->next;
    }

    // L2 hashed
    curr = head2;
    while (curr)
    {
        map[curr->data] = curr;
        curr = curr->next;
    }

    Node *UL = NULL;
    curr = 0;

    // iterate map and make final UL
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (UL == NULL)
        {
            UL = it->second;
            curr = UL;
        }
        else
        {
            curr->next = it->second;
            curr = curr->next;
        }
    }

    curr->next = 0;

    return UL;
}