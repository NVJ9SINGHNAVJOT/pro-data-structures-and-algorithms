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

// https://leetcode.com/problems/longest-common-prefix/description/

// Definition for a data structure
class TrieNode
{
public:
    char data;
    TrieNode *children[26] = {};
    bool isTerminal;
    int childCount;

    TrieNode(char d)
    {
        this->data = d;
        this->isTerminal = false;
        this->childCount = 0;
    }
};

void insertWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // not present
        child = new TrieNode(ch);
        root->childCount++;
        root->children[index] = child;
    }

    // recursion sambhal lega
    insertWord(child, word.substr(1));
}

void findLCP(string first, string &ans, TrieNode *root)
{
    if (root->isTerminal)
    {
        return;
    }

    for (int i = 0; i < first.length(); i++)
    {
        char ch = first[i];
        if (root->isTerminal)
        {
            break;
        }
        if (root->childCount == 1)
        {
            ans.push_back(ch);
            int index = ch - 'a';
            root = root->children[index];
        }
        else
        {
            break;
        }
    }
}

string longestCommonPrefix(vector<string> &strs)
{
    TrieNode *root = new TrieNode('-');
    for (int i = 0; i < strs.size(); i++)
    {
        insertWord(root, strs[i]);
    }

    string ans = "";
    findLCP(strs[0], ans, root);

    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}