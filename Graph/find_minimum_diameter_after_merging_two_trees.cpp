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
#include <math.h>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/

// make undirected graph
void makeGraph(vector<vector<int>> &edges, unordered_map<int, list<int>> &graph)
{
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}

int getDiameter(int parent, int src, unordered_map<int, list<int>> &graph, int &diameter)
{
    int secondMaxDepth = 0;
    int maxDepth = 0;

    for (int node : graph[src])
    {
        if (node == parent)
        {
            continue;
        }

        int depth = getDiameter(src, node, graph, diameter);

        if (depth > maxDepth)
        {
            secondMaxDepth = maxDepth;
            maxDepth = depth;
        }
        else if (depth > secondMaxDepth)
        {
            secondMaxDepth = depth;
        }

        diameter = max(diameter, maxDepth + secondMaxDepth);
    }
    return 1 + maxDepth;
}

int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    unordered_map<int, list<int>> graph1, graph2;

    makeGraph(edges1, graph1);
    makeGraph(edges2, graph2);

    int diameter = 0;
    int src1 = 0;

    getDiameter(-1, src1, graph1, diameter);

    int diameter1 = diameter;

    diameter = 0;
    int src2 = 0;

    getDiameter(-1, src2, graph2, diameter);

    int diameter2 = diameter;

    int combinedDiameter = ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;
    return max(combinedDiameter, max(diameter1, diameter2));
}

int main()
{
    // vector<vector<int>> edges1 = {
    //     {0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};

    // vector<vector<int>> edges2 = {
    //     {0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};

    // vector<vector<int>> edges1 = {
    //     {1, 0}, {2, 3}, {1, 4}, {2, 1}, {2, 5}};

    // vector<vector<int>> edges2 = {
    //     {4, 5}, {2, 6}, {3, 2}, {4, 7}, {3, 4}, {0, 3}, {1, 0}, {1, 8}};

    // vector<vector<int>> edges1 = {
    //     {3, 0}, {2, 1}, {2, 3}};

    // vector<vector<int>> edges2 = {
    //     {0, 1}, {0, 4}, {3, 5}, {6, 3}, {7, 6}, {2, 7}, {0, 2}, {8, 0}, {8, 9}};

    vector<vector<int>> edges1 = {
        {0, 1}, {2, 0}, {3, 2}, {3, 6}, {8, 7}, {4, 8}, {5, 4}, {3, 5}, {3, 9}};

    vector<vector<int>> edges2 = {
        {0, 1}, {0, 2}, {0, 3}};

    cout << minimumDiameterAfterMerge(edges1, edges2) << endl;
    return 0;
}