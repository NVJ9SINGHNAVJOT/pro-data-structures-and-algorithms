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
// question: distributing repeating integers
// example:
// answer:
// explanation:
// tags:

bool canDistributeHelper(vector<int> &counts, vector<int> &quantity, int ithCustomer)
{
    // base case
    if (ithCustomer >= quantity.size())
    {
        return true;
    }

    for (int i = 0; i < counts.size(); i++)
    {
        if (counts[i] >= quantity[ithCustomer])
        {
            counts[i] -= quantity[ithCustomer];
            if (canDistributeHelper(counts, quantity, ithCustomer + 1))
            {
                return true;
            }
            counts[i] += quantity[ithCustomer];
        }
    }

    return false;
}

bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> coutnMap;
    for (auto num : nums)
    {
        coutnMap[num]++;
    }
    vector<int> counts;
    for (auto it : coutnMap)
    {
        counts.push_back(it.second);
    }

    // sort and reverse so that if starting element is not allocated then return false
    sort(quantity.rbegin(), quantity.rend()); // can be removed also, as it helps only getting answer faster

    return canDistributeHelper(counts, quantity, 0);
}

int main()
{
    vector<int> nums = {1, 2, 3, 3};
    vector<int> quantity = {2};

    cout << canDistribute(nums, quantity) << endl;
    return 0;
}