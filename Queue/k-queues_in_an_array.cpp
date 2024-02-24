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
// question: k-queues in an array
// example:
// answer:
// explanation:
// tags:

class KQueue
{
public:
    int n, k, freespot;
    int *arr, *front, *rear, *next;

    KQueue(int _n, int _k) : n(_n), k(_k), freespot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    bool push(int x, int qi)
    {
        // overflow
        if (freespot == -1)
            return false;
        // find first free index
        int index = freespot;
        // update freespot
        freespot = next[index];
        // if first elememt in qi
        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // link new element to that q's rearest element
            next[rear[qi]] = index;
        }
        // update next
        next[index] = -1;
        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    int pop(int qi)
    {
        // underflow
        if (front[qi] == -1)
        {
            return -1;
        }
        // find index to pop
        int index = front[qi];
        // front update
        front[qi] = next[index];
        // update freespot
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << next[i] << ", ";
        }
        cout << endl;
        for (int i = 0; i < k; i++)
        {
            cout << front[i] << ", ";
        }
        cout << endl;
        for (int i = 0; i < k; i++)
        {
            cout << rear[i] << ", ";
        }
        cout << endl;
    }
};

int main()
{
    KQueue *q = new KQueue(5, 3);

    q->push(10, 0);
    q->push(20, 0);
    q->push(30, 1);
    q->push(40, 2);
    q->print();

    q->push(50, 2);
    q->print();

    cout << q->push(60, 1) << endl;
    cout << q->pop(1) << endl;
    cout << q->pop(1) << endl;
    cout << q->pop(2) << endl;

    return 0;
}