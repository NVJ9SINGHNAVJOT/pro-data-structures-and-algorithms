#include <iostream>
using namespace std;

// algorithm:
// question: kth ancestor
// example:
// answer:
// explanation:
// tags:

bool kthAncestor(Node *root, int &k, int p)
{
    // base cae
    if (root == NULL)
        return false;

    if (root->data == p)
    {
        return true;
    }

    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);

    // wapas aare honge
    // check left ya right me answer mila ya anhi
    if (leftAns || rightAns)
        k--;
    if (k == 0)
    {
        cout << "Answer: " << root->data << endl;
        // important to set k = -1
        k = -1;
    }

    return leftAns || rightAns;
}