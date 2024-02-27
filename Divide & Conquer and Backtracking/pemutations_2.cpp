#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

// algorithm:
// question: permutations 2
// example:
// answer:
// explanation:
// tags:

void permuteUniqueHelper(vector<int> &nums, vector<vector<int>> &ans, int start)
{
    // base case
    if (start >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited;

    for (int i = start; i < nums.size(); i++)
    {
        if (visited.find(nums[i]) != visited.end())
        {
            continue;
        }

        visited[nums[i]] = true;
        swap(nums[i], nums[start]);
        permuteUniqueHelper(nums, ans, start + 1);
        swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    permuteUniqueHelper(nums, ans, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = permuteUnique(nums);

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