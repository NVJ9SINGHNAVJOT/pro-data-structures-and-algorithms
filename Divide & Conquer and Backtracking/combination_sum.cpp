#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

void combinationSumHelper(vector<int> &nums, int target, vector<int> &v, vector<vector<int>> &ans, int index)
{
    // base case
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0)
    {
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        v.push_back(nums[i]);
        combinationSumHelper(nums, target - nums[i], v, ans, i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    vector<int> v;
    vector<vector<int>> ans;
    combinationSumHelper(nums, target, v, ans, 0);
    return ans;
}

int main()
{
    vector<int> nums = {2, 3, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum(nums, target);

    for (auto v : ans)
    {
        for (auto n : v)
        {
            cout << n << ", ";
        }
        cout << endl;
    }
    return 0;
}