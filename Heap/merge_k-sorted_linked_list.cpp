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
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/merge-k-sorted-lists/description/

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;

        int k = lists.size();
        if (k == 0)
            return NULL;

        // first element of every blinked list ko insert krdo heap me
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;

        while (!minHeap.empty())
        {
            ListNode *temp = minHeap.top();
            minHeap.pop();

            // temp may or may not be the first element of answer linked list
            if (head == NULL)
            {
                // temp -> first element of ans LL
                head = temp;
                tail = temp;
                if (tail->next != NULL)
                {
                    minHeap.push(tail->next);
                }
            }
            else
            {
                // temp isnnot the first element of LL
                tail->next = temp;
                tail = temp;
                if (tail->next != NULL)
                {
                    minHeap.push(tail->next);
                }
            }
        }
        return head;
    }
};