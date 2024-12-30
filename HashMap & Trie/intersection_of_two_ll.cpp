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

Node *findIntersection(Node *head1, Node *head2)
{
    unordered_map<int, int> map;
    Node *curr = head2;

    // hash2 items
    while (curr)
    {
        map[curr->data]++;
        curr = curr->next;
    }

    Node *IL = NULL;
    Node *it = 0;
    curr = head1;

    while (curr)
    {
        if (map.find(curr->data) != map.end())
        {
            if (!IL)
            {
                IL = curr;
                it = curr;
            }
            else
            {
                if (map[curr->data] > 0)
                {
                    it->next = curr;
                    it = it->next;
                    map[curr->data]--;
                }
            }
        }
        curr = curr->next;
    }
    it->next = NULL;

    return IL;
}