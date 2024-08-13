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
#include <numeric>
#include "../includes/bst.cpp"
#include "../includes/vector.cpp"
using namespace std;

// algorithm:
// question: replace every element with least greater element on/to it's right
// example:
// answer:
// explanation:
// tags:

Node *insert(Node *root, int val, int &succ)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val >= root->data)
    {
        root->right = insert(root->right, val, succ);
    }
    else
    {
        succ = root->data;
        root->left = insert(root->left, val, succ);
    }

    return root;
}

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    vector<int> ans(arr.size(), -1);
    Node *root = 0;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int succ = -1;
        root = insert(root, arr[i], succ);
        ans[i] = succ;
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 6, 9, 1, 3, 2};
    vector<int> ans = findLeastGreater(arr, arr.size());
    printVector(ans);
    return 0;
}