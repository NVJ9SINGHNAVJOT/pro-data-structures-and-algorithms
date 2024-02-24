#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm: divide and conquer
// question: quick sort
// example:
// answer:
// explanation:
// tags:

void quickSort(int arr[], int start, int end)
{
    // base case
    if (start >= end)
    {
        return;
    }
    int pivot = end;
    int i = start - 1;
    int j = start;
    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            ++i;
            swap(arr[i], arr[j]);
        }
        ++j;
    }

    ++i;
    swap(arr[i], arr[pivot]); // i is pivot element
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main()
{
    int arr[] = {90, 54, 88, 73, 21, 46, 89, 45};
    int end = 7;
    quickSort(arr, 0, end);

    for (auto num : arr)
    {
        cout << num << ", ";
    }
    cout << endl;
    return 0;
}