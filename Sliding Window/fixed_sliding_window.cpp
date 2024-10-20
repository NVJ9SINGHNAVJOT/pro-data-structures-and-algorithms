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

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    // we will store indexes in deque
    vector<int> ans;

    // process first k size window
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        // insert element
        dq.push_back(i);
    }

    // ans store karlo for 1st window
    ans.push_back(nums[dq.front()]);

    // remaining windows
    for (int i = k; i < nums.size(); i++)
    {
        // removal
        if (!dq.empty() && i - k >= dq.front())
            dq.pop_front();

        // additional
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        // insert element
        dq.push_back(i);

        /// ans store
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{
    int k = 3;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    cout << maxSlidingWindow(nums, k) << endl;
    return 0;
}