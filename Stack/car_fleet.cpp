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

static bool myComp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<pair<int, int>> cars;
    for (int i = 0; i < position.size(); i++)
    {
        cars.push_back({position[i], speed[i]});
    }

    sort(cars.begin(), cars.end());

    stack<float> st;

    for (auto car : cars)
    {
        float time = (target - car.first) / ((float)car.second);
        while (!st.empty() && time >= st.top())
        {
            st.pop();
        }
        st.push(time);
    }

    return st.size();
}

int main()
{
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;

    int ans = carFleet(target, position, speed);

    cout << ans << endl;
    return 0;
}