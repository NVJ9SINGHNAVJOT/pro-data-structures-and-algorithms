#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

// algorithm: bubble sort
// question:
// example:
// answer:
// explanation:
// tags:

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {                         // n - 1 rounds
        bool swapped = false; // to keep track whether swap occured or not
        for (int j = 1; j < n - i; j++)
        { // excluding the last i elements in ith round and j = 1 as we have to access j - 1 index
            if (arr[j - 1] > arr[j])
            {
                swapped = true;
                swap(arr[j - 1], arr[j]);
            }
        }
        if (!swapped)
        { // if nothing gets swapped then break from the outer loop as array is sorted
            break;
        }
    }
}

int main()
{
    vector<int> arr{10, 1, 4, 8, 5, 7};
    cout << "Printing before sorted " << endl;
    printArr(arr);
    cout << "Printing array after sorting " << endl;
    bubbleSort(arr);
    printArr(arr);
    return 0;
}