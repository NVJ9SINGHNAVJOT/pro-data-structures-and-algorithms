#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

// algorithm:
// question: circular tower-gas station
// example:
// answer:
// explanation:
// tags:

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{

    // kitna petrol kam padgya
    int deficit = 0;
    // kitna petrol bacha hua h
    int balance = 0;
    // circuit kaha se start krre ho
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            // yahi pr galti hogi
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }

    if (balance >= deficit)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int canCompleteCircuit2(vector<int> &gas, vector<int> &cost)
{
    bool ended = false;
    for (int i = 0; i < gas.size(); i++)
    {
        if (gas[i] >= cost[i])
        {
            int ans = i;
            int count = 1;
            int tank = gas[i] - cost[i];
            if (i == gas.size() - 1)
            {
                i = 0;
                ended = true;
            }
            else
            {
                i++;
            }

            while (tank > -1)
            {
                tank += gas[i];
                tank -= cost[i];
                if (tank > -1)
                {
                    count++;
                }
                else
                {
                    break;
                }
                if (count == gas.size())
                {
                    return ans;
                }
                i++;
                if (i == gas.size())
                {
                    i = 0;
                    ended = true;
                }
            }
            i--;
        }
        if (ended)
        {
            return -1;
        }
    }
    return -1;
}