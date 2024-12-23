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
#include "../includes/vector.cpp"
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https -> link

class TrieNode
{
public:
    char data;
    TrieNode *children[26] = {};
    bool isTerminal;

    TrieNode(char d)
    {
        this->data = d;
        this->isTerminal = false;
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
        root->children[index] = child;
    }

    // recursion sambhal lega
    insertWord(child, word.substr(1));
}

void storeSuggestions(TrieNode *curr, vector<string> &output, string &prefix)
{
    if (curr->isTerminal)
    {
        output.push_back(prefix);
    }

    // a to z tak choices dedo
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        TrieNode *next = curr->children[index];
        if (next != NULL)
        {
            // child exists
            prefix.push_back(ch);
            storeSuggestions(next, output, prefix);
            prefix.pop_back();
        }
    }
}

vector<string> getSuggestions(TrieNode *root, string input)
{
    vector<string> output;
    TrieNode *curr = root;
    TrieNode *next;

    for (int i = 0; i < input.size(); i++)
    {
        char lastCh = input[i];
        int index = lastCh - 'a';

        next = curr->children[index];

        if (next == NULL)
        {
            return output;
        }
        curr = next;
    }

    // take out all suggestions for firstChar
    storeSuggestions(next, output, input);

    return output;
}

int main()
{
    TrieNode *root = new TrieNode('-');
    vector<string> strs = {"coding", "coder", "codehelp", "code", "codeverse", "codingdunia", "codeforces", "cod", "cb", "test"};
    for (int i = 0; i < strs.size(); i++)
    {
        insertWord(root, strs[i]);
    }

    vector<string> answer = getSuggestions(root, "code");

    printVector(answer);

    return 0;
}