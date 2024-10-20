#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/copy-list-with-random-pointer/description/

// Definition for a data structure
class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int _data)
    {
        data = _data;
        next = NULL;
        random = NULL;
    }
};

// method 1
Node *helper(Node *head, unordered_map<Node *, Node *> &mp)
{
    if (head == 0)
        return 0;

    Node *newHead = new Node(head->data);
    mp[head] = newHead;
    newHead->next = helper(head->next, mp);

    // now for copying random pointers
    if (head->random)
    {
        newHead->random = mp[head->random];
    }

    return newHead;
}

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;
    return helper(head, mp);
}




// method 2
Node *copyRandomList(Node *head)
{
    if (!head)
        return 0;

    // step 1: clone A -> A'
    Node *it = head; // iterate over old head
    while (it)
    {
        Node *clonedNode = new Node(it->data);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
    }

    // step 2: assign random links of A' with help A
    it = head;
    while (it)
    {
        Node *clonedNode = it->next;
        clonedNode->random = it->random ? it->random->next : nullptr;
        it = it->next->next;
    }

    // step 3: detach A' from A
    it = head;
    Node *clonedHead = it->next;
    while (it)
    {
        Node *clonedNode = it->next;
        it->next = it->next->next;

        if (clonedNode->next)
        {
            clonedNode->next = clonedNode->next->next;
        }
        it = it->next;
    }
    return clonedHead;
}