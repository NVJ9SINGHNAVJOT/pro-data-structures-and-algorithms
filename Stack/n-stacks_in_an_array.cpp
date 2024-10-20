#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

class NStack
{
    int *a, *top, *next;
    int n;
    int size;
    int freespot;

public:
    NStack(int _n, int _s) : n(_n), size(_s)
    {
        freespot = 0;
        a = new int[size];    // a array
        top = new int[n];     // top array
        next = new int[size]; // next array

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }

    ~NStack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }

    bool push(int x, int m)
    {
        if (freespot == -1)
            return false; // stack is full

        // 1. find index
        int index = freespot;

        // 2. update freespot
        freespot = next[index];

        // 3. insert
        a[index] = x;

        // 4. update top
        next[index] = top[m - 1];

        // 5.update top
        top[m - 1] = index;

        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1; // stack is underflow

        int index = top[m - 1];

        top[m - 1] = next[index];

        int poppedElement = a[index];

        next[index] = freespot;

        freespot = index;

        return poppedElement;
    }

    void printInitializeArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << ", ";
        }
        cout << endl;
    }
};

int main()
{
    NStack s = NStack(3, 6);

    s.push(55, 1);
    s.push(2, 2);
    s.push(8, 1);
    s.push(10, 3);
    s.push(66, 1);

    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(2) << endl;

    s.printInitializeArray();

    return 0;
}