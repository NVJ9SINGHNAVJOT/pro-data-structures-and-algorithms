#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

void printSubSequence(string str, string output, int i)
{
    // Base Case
    if (i >= str.length())
    {
        // print and then return
        cout << output << endl;
        return;
    }

    // Call for exclude (As it is)          exclude
    printSubSequence(str, output, i + 1);
    
    // Call for include (Concatenate)       include
    output.push_back(str[i]);
    printSubSequence(str, output, i + 1);
}

int main()
{
    string str = "abc";
    string output = ""; // Initially empty
    int i = 0;
    printSubSequence(str, output, i);
    return 0;
}