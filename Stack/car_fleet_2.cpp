#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

vector<double> getCollisionsTimes(vector<vector<int>> &cars)
{
    vector<double> answer(cars.size(), -1);
    stack<int> st;

    for (int i = cars.size() - 1; i >= 0; i--)
    {
        // check if car ahead of current car is faster
        while (!st.empty() && cars[st.top()][1] >= cars[i][1])
        {
            st.pop();
        }

        // now check for collision time
        while (!st.empty())
        {
            double colTime = (double)(cars[st.top()][0] - cars[i][0]) /
                             (cars[i][1] - cars[st.top()][1]);

            if (answer[st.top()] == -1 || colTime <= answer[st.top()])
            {
                answer[i] = colTime;
                break;
            }
            st.pop();
        }
        st.push(i);
    }
    return answer;
}

int main()
{
    vector<vector<int>> cars = {{3, 4},
                                {5, 4},
                                {6, 3},
                                {9, 1}};

    vector<double> ans = getCollisionsTimes(cars);
    for (auto t : ans)
    {
        cout << t << ", ";
    }
    cout << endl;
    return 0;
}