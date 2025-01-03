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

// https://leetcode.com/problems/top-k-frequent-words/description/

class comp
{
public:
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
        return a.first == b.first ? a < b : a.first > b.first;
    }
};

class TrieNode
{
public:
    char data;
    TrieNode *children[26] = {};
    bool isTerminal;
    int freq;

    TrieNode(char d)
    {
        this->data = d;
        this->isTerminal = false;
        this->freq = 0;
    }
};

class Trie
{
    TrieNode *root = new TrieNode('-');
    void insertWordHelper(TrieNode *root, string &word, int &i)
    {
        // base case
        if (i >= word.length())
        {
            root->freq++;
            root->isTerminal = true;
            return;
        }

        char ch = word[i++];
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
            root->children[index] = child;
        }

        // recursion sambhal lega
        insertWordHelper(child, word, i);
    }

    bool searchWordHelper(TrieNode *root, string &word, int &i)
    {
        // base case
        if (i == word.length())
        {
            return root->isTerminal;
        }

        char ch = word[i++];
        int index = ch - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        // rec call
        return searchWordHelper(child, word, i);
    }

public:
    void insertWord(string word)
    {
        int i = 0;
        this->insertWordHelper(this->root, word, i);
    }
    bool searchWord(string word)
    {
        int i = 0;
        return this->searchWordHelper(this->root, word, i);
    }
    void traverseHelper(TrieNode *root, string &s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int &k)
    {
        if (!root)
        {
            return;
        }
        if (root->isTerminal)
        {
            if (pq.size() < k)
            {
                pq.push({root->freq, s});
            }
            else if (pq.size() == k && root->freq > pq.top().first)
            {
                pq.pop();
                pq.push({root->freq, s});
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                s.push_back(i + 'a');
                traverseHelper(root->children[i], s, pq, k);
                s.pop_back();
            }
        }
    }

    void traverse(priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int &k)
    {
        string word = "";
        this->traverseHelper(this->root, word, pq, k);
    }
};

vector<string> topKFrequent(vector<string> &words, int k)
{
    Trie trie;
    vector<string> ans;

    for (auto word : words)
    {
        trie.insertWord(word);
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
    trie.traverse(pq, k);

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.second);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}