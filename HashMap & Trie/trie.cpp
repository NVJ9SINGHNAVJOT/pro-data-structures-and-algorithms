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

class Trie
{
    TrieNode *root = new TrieNode('-');
    void insertWordHelper(TrieNode *root, string &word, int &i)
    {
        // base case
        if (i >= word.length())
        {
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
};

int main()
{
    Trie *trie = new Trie();

    trie->insertWord("coding");
    trie->insertWord("code");
    trie->insertWord("coder");
    trie->insertWord("codehelp");
    trie->insertWord("baba");
    trie->insertWord("baby");
    trie->insertWord("babu");
    trie->insertWord("shona");
    trie->insertWord("chakme");

    cout << "Searching 'chakme': ";
    if (trie->searchWord("chakme"))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "absent" << endl;
    }
}