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

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    // distTravelled
    int distTravelled = startFuel;

    // initall check if for station 0
    if (stations.size() > 0 && distTravelled < stations[0][0])
    {
        return -1;
    }

    int count = 0;
    priority_queue<int> pq; // maxHeap
    for (int i = 0; i < stations.size(); i++)
    {
        if (distTravelled < stations[i][0])
        {
            while (distTravelled < stations[i][0] && !pq.empty())
            {
                distTravelled += pq.top();
                pq.pop();
                count++;
            }
            if (distTravelled < stations[i][0])
            {
                return -1;
            }
        }
        if (distTravelled >= target)
        {
            return count;
        }

        pq.push(stations[i][1]);
    }

    // now check for target
    while (distTravelled < target && !pq.empty())
    {
        distTravelled += pq.top();
        pq.pop();
        count++;
    }

    if (distTravelled >= target)
    {

        return count;
    }

    return -1;
}