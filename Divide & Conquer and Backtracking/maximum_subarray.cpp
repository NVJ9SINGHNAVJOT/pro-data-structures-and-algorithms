#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm: kadane's algorithm
// example:
// answer:
// explanation:
// tags:

int maxSumArrayHelper(vector<int> &v, int start, int end)
{
    if (start >= end)
    {
        return v[start];
    }

    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int mid = start + ((end - start) >> 1);

    int maxLeftSum = maxSumArrayHelper(v, start, mid);
    int maxRightSum = maxSumArrayHelper(v, mid + 1, end);

    // max gross border sum
    int leftBorderSum = 0, rightBorderSum = 0;
    for (int i = mid; i >= 0; i--)
    {
        leftBorderSum += v[i];
        if (leftBorderSum > maxLeftBorderSum)
        {
            maxLeftBorderSum = leftBorderSum;
        }
    }

    for (int i = mid + 1; i <= end; i++)
    {
        rightBorderSum += v[i];
        if (rightBorderSum > maxRightBorderSum)
        {
            maxRightBorderSum = rightBorderSum;
        }
    }

    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

    return max(crossBorderSum, max(maxLeftSum, maxRightSum));
}

int maxSubArray(vector<int> &nums)
{
    return maxSumArrayHelper(nums, 0, nums.size() - 1);
}

int maxSubArray2(vector<int> &nums)
{
    int n = nums.size();

    int maxSum = INT_MIN;
    int currSum = 0;

    int start = -1;
    int end = -1;

    for (int i = 0; i < n; i++)
    {
        if (currSum == 0)
        {
            start = i;
        }

        // add current element in currSum
        currSum = currSum + nums[i];

        // check if currSum is greater than maxSum
        if (currSum > maxSum)
        {
            maxSum = currSum;
            end = i;
        }

        // if with addition of current element currSum goes to negative
        // then currSum set to 0 as we dont want to carry -ive sum further
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    cout << start << ", " << end << endl;
    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSubArray2(nums);
    cout << ans << endl;
    return 0;
}