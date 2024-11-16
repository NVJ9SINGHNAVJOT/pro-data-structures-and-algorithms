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
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/edit-distance/description/

int solveRec(string &word1, string &word2, int i, int j)
{
    if (i == word1.length())
    {
        return word2.length() - j;
    }
    if (j == word2.length())
    {
        return word1.length() - i;
    }
    int ans = 0;
    if (word1[i] == word2[j])
    {
        ans = solveRec(word1, word2, i + 1, j + 1);
    }
    else
    {
        int insert = 1 + solveRec(word1, word2, i, j + 1);
        int deleted = 1 + solveRec(word1, word2, i + 1, j);
        int replace = 1 + solveRec(word1, word2, i + 1, j + 1);
        ans = min(insert, min(deleted, replace));
    }
    return ans;
}

int minDistance(string word1, string word2)
{
    if (word1.length() == 0)
    {
        return word2.length();
    }
    if (word2.length() == 0)
    {
        return word1.length();
    }
    int ans;
    ans = solveRec(word1, word2, 0, 0);

    return ans;
}