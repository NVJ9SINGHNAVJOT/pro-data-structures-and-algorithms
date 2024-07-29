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
void printVector(vector<T> &vector)
{
    cout << endl;
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << ", ";
    }
    cout << endl;
}

template <typename T>
void print2DVector(vector<T> &vector)
{
    cout << endl;
    for (int i = 0; i < vector.size(); i++)
    {
        for (int j = 0; j < vector[i].size(); j++)
        {
            cout << vector[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T>
void print3DVector(vector<T> &vector)
{
    cout << endl;
    for (int i = 0; i < vector.size(); i++)
    {
        for (int j = 0; j < vector[i].size(); j++)
        {
            for (int k = 0; k < vector[j].size(); k++)
            {
                cout << vector[i][j][k] << ", ";
            }
        }
        cout << endl;
    }
    cout << endl;
}