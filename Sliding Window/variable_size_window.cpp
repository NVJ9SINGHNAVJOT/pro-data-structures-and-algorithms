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

// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int sum = 0;
        int len = INT_MAX;

        while (j < nums.size())
        {
            // include current number
            sum = sum + nums[j];
            // mere paas ek window ka sum ready h
            while (sum >= target)
            {
                // minimise -> sum me se decrease karo, len bhi update krelna, i(start) ko aage badhana padega
                len = min(len, j - i + 1);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }

        if (len == INT_MAX)
            return 0;
        else
            return len;
    }
};