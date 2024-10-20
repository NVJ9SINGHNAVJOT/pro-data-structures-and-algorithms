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

// algorithm: sliding window
// example:
// answer:
// explanation:
// tags:

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    // first window of k size
    for (int i = 0; i < k; i++)
    {
        // chote element remove krdo,
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        // inserting index, so that we can checkout of window element
        dq.push_back(i);
    }

    // store answer for first window
    ans.push_back(nums[dq.front()]);

    // remaining windows ko process
    for (int i = k; i < nums.size(); i++)
    {
        // out of window element ko remove krdia
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // ab ferse current element k liye chotte element
        // ko remove krna h
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        // inserting index, so tht we can checkout of window element
        dq.push_back(i);

        // current window ka answer store krna h
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);

    for (auto n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}