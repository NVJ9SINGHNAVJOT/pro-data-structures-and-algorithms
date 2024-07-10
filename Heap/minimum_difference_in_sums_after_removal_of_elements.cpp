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
// question: minimum difference in sums after removal of elements
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/

#define ll long long

long long minimumDifference(vector<int> &nums)
{
    int n = nums.size() / 3;
    // prefix[i] = sum of min n elements from left side
    // suffix[i] = sum of max n elements form right side

    vector<ll> prefix(nums.size(), -1);
    vector<ll> suffix(nums.size(), -1);

    // complete prefix array
    ll sum = 0;
    priority_queue<ll> pq; // maxHeap
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        pq.push(nums[i]);
        if (pq.size() > n)
        {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == n)
        {
            prefix[i] = sum;
        }
    }

    // complete suffix array
    sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq2; // minHeap
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        sum += nums[i];
        pq2.push(nums[i]);
        if (pq2.size() > n)
        {
            sum -= pq2.top();
            pq2.pop();
        }
        if (pq2.size() == n)
        {
            suffix[i] = sum;
        }
    }

    // now get min ans from prefix - suffix
    ll ans = LONG_LONG_MAX;
    for (int i = n - 1; i < 2 * n; i++)
    {
        ans = min(ans, prefix[i] - suffix[i + 1]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {7, 9, 5, 8, 1, 3};
    cout << minimumDifference(nums) << endl;
    return 0;
}