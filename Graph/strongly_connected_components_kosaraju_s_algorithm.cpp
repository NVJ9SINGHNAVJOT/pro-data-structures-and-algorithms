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
using namespace std;

// algorithm:
// question: strongly connected components kosaraju's algorithm
// example:
// answer:
// explanation:
// tags:

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    // graph should be directed acyclic
    void topSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[src] = true;

        for (int nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                topSortDfs(nbr, visited, ans);
            }
        }

        ans.push(src);
    }

    void dfs2(int src, unordered_map<int, bool> &visited2, unordered_map<int, list<int>> &adjNew)
    {
        visited2[src] = true;
        for (auto nbr : adjNew[src])
        {
            if (!visited2[nbr])
            {
                dfs2(nbr, visited2, adjNew);
            }
        }
    }

    int countSCC(int n)
    {
        stack<int> s;
        unordered_map<int, bool> visited;

        // topoSortDfs
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                topSortDfs(i, visited, s);
            }
        }

        // reverse all edges
        unordered_map<int, list<int>> adjNew;
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr;
                adjNew[v].push_back(u);
            }
        }

        // traverse using dfs (just traverse)
        int count = 0;
        unordered_map<int, bool> visited2;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (!visited2[node])
            {
                count++;
                dfs2(node, visited2, adjNew);
            }
        }

        return count;
    }
};

int main()
{
    Graph g;

    // g.addEdge(srcNode, destNode, direction);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);

    g.printAdjacencyList();

    cout << g.countSCC(g.adjList.size()) << endl;

    return 0;
}