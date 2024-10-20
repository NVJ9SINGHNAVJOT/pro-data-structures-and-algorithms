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

class MyStack
{
public:
    queue<int> q;

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    int pop()
    {
        int top = q.front();
        q.pop();
        return top;
    }

    int peek()
    {
        int top = q.front();
        return top;
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;

    return 0;
}
