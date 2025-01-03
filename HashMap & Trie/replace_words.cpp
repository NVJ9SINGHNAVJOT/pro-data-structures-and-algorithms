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

// https://leetcode.com/problems/replace-words/description/

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

bool search(TrieNode *root, string &word, int &i)
{
    // base case
    if (root->isTerminal)
    {
        return true;
    }
    if (i >= word.length())
    {
        return root->isTerminal;
    }

    int index = word[i++] - 'a';
    if (root->children[index])
    {
        return search(root->children[index], word, i);
    }

    return false;
}

int getIndex(TrieNode *root, string word)
{
    int i = 0;
    bool gotIt = search(root, word, i);

    return gotIt ? i : -1;
}

string replaceWords(vector<string> &dictionary, string sentence)
{
    string ans;
    TrieNode *trie = new TrieNode('-');

    // inset into trie all dictionary
    for (auto root : dictionary)
    {
        insertWord(trie, root);
    }

    // pick each word and fing in trie root is available or not
    int start = 0, end = 0;
    while (end < sentence.size())
    {
        if (sentence[end] == ' ' || end == sentence.size() - 1)
        {
            int len = end == sentence.size() - 1 ? sentence.size() : end - start;
            string word = sentence.substr(start, len);
            int trieMatchIndex = getIndex(trie, word);

            ans += trieMatchIndex != -1 ? word.substr(0, trieMatchIndex) : word;

            if (sentence[end] == ' ')
            {
                ans += ' ';
            }

            start = end + 1;
        }

        ++end;
    }
    return ans;
}

int main()
{
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    cout << replaceWords(dictionary, sentence) << endl;
    return 0;
}