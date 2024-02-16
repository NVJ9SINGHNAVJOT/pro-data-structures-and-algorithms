#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// algorithm:
// question: create min stack
// example:
// answer:
// explanation:
// tags:

class MinStack
{
public:
    vector<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            pair<int, int> p = make_pair(val, val);
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.back().first;
    }

    int getMin()
    {
        return st.back().second;
    }
};

int main()
{
    MinStack *s = new MinStack;

    s->push(7);
    s->pop();

    return 0;
}