#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// question: print spiral traversal of a matrix
// example:
// answer:
// explanation:
// tags:


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans; // to store the result
    int n = matrix.size(); // number of rows
    int m = matrix[0].size(); // number of columns
    int top = 0, left = 0, bottom = n - 1, right = m - 1; // pointers for traversal
    int totalElements = n * m; 
    int count = 0;

    while (top <= bottom && left <= right  && totalElements > count) {

        // print the top row from left to right
        for (int i = left; i <= right && totalElements > count; i++) {
            count++;
            ans.push_back(matrix[top][i]);
        }

        top++; // increment the top pointer

        // print the right column from top to bottom
        for (int i = top; i <= bottom && totalElements > count; i++) {
            count++;
            ans.push_back(matrix[i][right]);
        }

        right--; // decrement the right pointer

        // print the bottom row from right to left
        for (int i = right; i >= left && totalElements > count; i--) {
            count++;
            ans.push_back(matrix[bottom][i]);
        }

        bottom--; // decrement the bottom pointer
        
        // print the left column from bottom to top
        for (int i = bottom; i >= top && totalElements > count; i--) {
            count++;
            ans.push_back(matrix[i][left]);
        }

        left++; // increment the left pointer
        
    }
    return ans; // return the result
}

int main() {
    
    // sample matrix
    vector<vector<int>> matrix {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
    // call the function
    vector<int> ans = spiralOrder(matrix);
    // print the result
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}