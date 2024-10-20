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

void reverseKElements(queue<int> &q, int k)
{
    // StepA: queue ->k elements  -> stack

    stack<int> s;
    int count = 0;
    int n = q.size();

    if (k <= 0 || k > n)
        return;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if (count == k)
            break;
    }

    // stepB: stack -> q me qapas
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    // step C: push n-k element from q front to back
    count = 0;
    while (!q.empty() && n - k != 0)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if (count == n - k)
            break;
    }
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseKElements(q, 3);
    while (!q.empty())
    {
        cout << q.front() << ", ";
        q.pop();
    }

    cout << endl;
    return 0;
}