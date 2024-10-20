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

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // step 1: put all elements of q into s
    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        s.push(element);
    }

    // step2: put all element from stackinto q
    while (!s.empty())
    {
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void reverseQueueRecursion(queue<int> &q)
{
    // Base case
    if (q.empty())
        return;

    // step A
    int temp = q.front();
    q.pop();

    // step B
    reverseQueueRecursion(q);

    // step C;
    q.push(temp);
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueueRecursion(q);
    return 0;
}