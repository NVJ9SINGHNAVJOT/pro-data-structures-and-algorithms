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
using namespace std;
template <typename T>

class Array2D
{
public:
    int sizeOfRow;
    int sizeOfCol;

    Array2D(int sizeOfRow, int sizeOfCol)
    {
        this->sizeOfRow = sizeOfRow;
        this->sizeOfCol = sizeOfCol;
    }

    void print2DArray(T **array)
    {
        cout << endl;
        for (int x = 0; x < sizeOfRow; x++)
        {
            for (int y = 0; y < sizeOfCol; y++)
            {
                cout << array[x][y] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

template <typename T>

void printArray(T array[], int sizeOfArray)
{
    cout << endl;
    for (int x = 0; x < sizeOfArray; x++)
    {
        cout << array[x] << ", ";
    }
    cout << endl;
}
