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
#include <iostream>
#include <bitset>
using namespace std;

void printBits(int number)
{
    const int bitCount = sizeof(number) * 8;
    bitset<bitCount> bits(number); // Convert number to a bitset for easier bit manipulation

    cout << "Integer: " << number << " Bits: " << bitCount << endl;
    // Print bit indices
    for (int i = bitCount - 1; i >= 0; --i)
    {
        cout << i % 10; // Print only the last digit of the index for clarity
    }
    cout << endl;

    // Print bit values
    for (int i = bitCount - 1; i >= 0; --i)
    {
        cout << bits[i];
    }
    cout << endl;
}
