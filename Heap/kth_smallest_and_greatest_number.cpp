#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

int getKthGreatestElement(int arr[], int n, int k)
{
    // create min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    // insert inital k elements of array
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // for remaining elements, push only if they are greater than top
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if (element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}

int getKthSmallestElement(int arr[], int n, int k)
{
    // create max heap
    priority_queue<int> pq;
    // insert inital k elements of array
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // for remaining elements, push only if they are less than top
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if (element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 5;

    cout << "Kth greatest : Ans is: " << getKthGreatestElement(arr, n, k) << endl;
    cout << "Kth smallest : Ans is: " << getKthSmallestElement(arr, n, k) << endl;
    cout << "Kth greatest : Ans is: " << getKthGreatestElement(arr, n, 1) << endl;
    cout << "Kth smallest : Ans is: " << getKthSmallestElement(arr, n, 1) << endl;
    return 0;
}