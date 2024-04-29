#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back({v, weight});
        if (direction == 0)
        {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << "(" << neighbour.first << "," << neighbour.second << "), ";
            }
            cout << endl;
        }
    }

    void shortestPathBfs(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial steps for src
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        // now start traversing from source
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        // store path in ans, after traversing on parent map
        vector<int> ans;
        int node = dest;
        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout << "printing answer: " << endl;
        for (auto i : ans)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main()
{
    Graph g1;
    // g1.addEdge(srcNode, destNode, weight, direction);
    g1.addEdge(0, 1, 1, 1);
    g1.addEdge(0, 2, 1, 1);
    g1.addEdge(0, 3, 1, 1);
    g1.addEdge(1, 4, 1, 1);
    g1.addEdge(2, 5, 1, 1);
    g1.addEdge(3, 6, 1, 1);
    g1.addEdge(4, 5, 1, 1);
    g1.addEdge(6, 5, 1, 1);

    g1.printAdjacencyList();

    g1.shortestPathBfs(0, 5);

    return 0;
}
