#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: in place merge sort
// example:
// answer:
// explanation:
// tags:

void mergeInPlace(vector<int> &v, int start, int end)
{
    int total_len = end - start + 1;
    // ceil
    int gap = total_len / 2 + total_len % 2;
    while (gap > 0)
    {
        int i = start, j = start + gap;
        while (j <= end)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
            ++i, ++j;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

void mergeSort(vector<int> &v, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) >> 1;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    mergeInPlace(v, start, end);
}

vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 8, 9, 12, 13, 3, 4, 7, 10};
    nums = sortArray(nums);
    for (auto n : nums)
    {
        cout << n << ", ";
    }
    cout << endl;
    return 0;
}