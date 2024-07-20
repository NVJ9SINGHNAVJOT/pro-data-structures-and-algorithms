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
// question:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/path-with-minimum-effort/description/

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> maxHeap;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> firstTime(n, vector<bool>(m, 1));
        maxHeap.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!maxHeap.empty())
        {
            auto fNode = maxHeap.top();
            maxHeap.pop();
            int frontNodeDifference = fNode.first;
            int x = fNode.second.first;
            int y = fNode.second.second;

            // check ans tak toh nahi pahuch agye
            if (frontNodeDifference >= dist[x][y] && firstTime[x][y] == false)
            {
                // already answer exist for this coordinates
                continue;
            }
            if (x == n - 1 && y == m - 1)
            {
                // cannot go further as this is destination coordinate
                continue;
            }
            firstTime[x][y] = false;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m)
                {
                    int currDifference = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(frontNodeDifference, currDifference);
                    if (newMax < dist[newX][newY])
                    {
                        dist[newX][newY] = newMax;
                        maxHeap.push({newMax, {newX, newY}});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        return dist[n - 1][m - 1];
    }
};

// this is better approach and as dijkastra algo is used to automatically get node which have got answer
// int minimumEffortPath(vector<vector<int>>& heights) {
//     priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
//     vector<vector<int> > dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
//     pq.push({0, {0,0}});
//     dist[0][0] = 0;
//     while(!pq.empty()) {
//         auto fNode = pq.top();
//         pq.pop();
//         int frontNodeDifference = fNode.first;
//         int x = fNode.second.first;
//         int y = fNode.second.second;
//         //check ans tak toh nahi pahuch agye
//         if(x == heights.size() - 1 && y == heights[0].size() - 1) {
//             return dist[x][y];
//         }
//         int dx[] = {-1,0,1,0};
//         int dy[] = {0,1,0,-1};
//         for(int i=0; i<4; i++) {
//             int newX = x + dx[i];
//             int newY = y + dy[i];
//             if(newX >=0 && newY >=0 && newX <heights.size() && newY < heights[0].size()) {
//                 int currDifference = abs(heights[x][y] - heights[newX][newY]);
//                 int newMax = max(frontNodeDifference, currDifference);
//                 if(newMax < dist[newX][newY]) {
//                     dist[newX][newY] = newMax;
//                     pq.push({newMax, {newX, newY}});
//                 }
//             }
//         }
//     }
//     return 0;
// }