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
// question: longest happy string
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/longest-happy-string/description/

class Node
{
public:
    char data;
    int count;

    Node(char d, int c)
    {
        data = d;
        count = c;
    }
};

class Compare
{
public:
    bool operator()(Node a, Node b)
    {
        return a.count < b.count;
    }
};

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<Node, vector<Node>, Compare> maxHeap;

        if (a > 0)
        {
            Node temp('a', a);
            maxHeap.push(temp);
        }

        if (b > 0)
        {
            Node temp('b', b);
            maxHeap.push(temp);
        }

        if (c > 0)
        {
            Node temp('c', c);
            maxHeap.push(temp);
        }

        string ans = "";

        while (maxHeap.size() > 1)
        {
            Node first = maxHeap.top();
            maxHeap.pop();
            Node second = maxHeap.top();
            maxHeap.pop();

            // first node
            if (first.count >= 2)
            {
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }
            else
            {
                ans += first.data;
                first.count--;
            }

            // second node
            if (second.count >= 2 && second.count >= first.count)
            {
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            }
            else
            {
                ans += second.data;
                second.count--;
            }

            if (first.count > 0)
            {
                maxHeap.push(first);
            }

            if (second.count > 0)
            {
                maxHeap.push(second);
            }
        }

        if (maxHeap.size() == 1)
        {
            Node temp = maxHeap.top();
            maxHeap.pop();

            if (temp.count >= 2)
            {
                ans += temp.data;
                ans += temp.data;
                temp.count -= 2;
            }
            else
            {
                ans += temp.data;
                temp.count--;
            }
        }
        return ans;
    }
};
