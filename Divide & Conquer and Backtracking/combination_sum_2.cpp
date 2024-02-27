#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: combination sum 2
// example:
// answer:
// explanation:
// tags:

void combinationSum2Helper(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
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

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        v.push_back(candidates[i]);
        combinationSum2Helper(candidates, target - candidates[i], v, ans, i + 1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> v;
    vector<vector<int>> ans;
    combinationSum2Helper(candidates, target, v, ans, 0);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> ans = combinationSum2(candidates, target);

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