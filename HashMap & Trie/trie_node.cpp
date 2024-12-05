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

bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
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
        return false;
    }

    // rec call
    return searchWord(child, word.substr(1));
}

bool deleteWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        // If word ends here and is terminal, unmark it
        if (!root->isTerminal)
        {
            return false; // Word does not exist
        }
        root->isTerminal = false; // Unmark as terminal
        // Return true if the current node has no children (can be deleted)
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                return false; // Current node cannot be deleted
            }
        }
        return true; // Node can be deleted
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode *child = root->children[index];
    if (child == NULL)
    {
        return false; // Word does not exist
    }

    // Recursive call
    bool shouldDeleteChild = deleteWord(child, word.substr(1));

    // If the child node can be deleted
    if (shouldDeleteChild)
    {
        delete child;
        root->children[index] = NULL;

        // Check if current node can also be deleted
        if (root->isTerminal)
        {
            return false; // Current node is terminal, cannot delete
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                return false; // Current node has other children, cannot delete
            }
        }
        return true; // Current node can be deleted
    }

    return false; // No nodes deleted above
}

int main()
{
    TrieNode *root = new TrieNode('-');

    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");
    insertWord(root, "shona");
    insertWord(root, "chakme");

    cout << "Searching 'chakme': ";
    if (searchWord(root, "chakme"))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "absent" << endl;
    }

    cout << "Deleting 'chakme'" << endl;
    deleteWord(root, "chakme");

    cout << "Searching 'chakme' after deletion: ";

    if (searchWord(root, "chakme"))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "absent" << endl;
    }

    return 0;
}