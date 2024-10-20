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
// example:
// answer:
// explanation:
// tags:

// https -> link

// Definition for a data structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

ListNode *llToBST(ListNode *&head, int s, int e)
{
    if (head == NULL || s > e)
    {
        return NULL;
    }

    int m = (s + e) / 2;
    // prev is left, next is right

    // left
    ListNode *leftroot = llToBST(head, s, m - 1);

    // main
    ListNode *mainNode = head;
    mainNode->prev = leftroot;
    head = head->next;

    // right
    ListNode *rightroot = llToBST(head, m + 1, e);
    mainNode->next = rightroot;

    return mainNode;
}