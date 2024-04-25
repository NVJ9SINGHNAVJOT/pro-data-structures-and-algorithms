#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    // graph created with unordered_map
    // weight are integers only
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, bool direction, int weight = 1)
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

    void bfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            // insert neighbours
            for (pair<int, int> neighbour : adjList[frontNode])
            {
                if (!visited[neighbour.first])
                {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (pair<int, int> neighbour : adjList[src])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited);
            }
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (pair<int, int> neighbour : node.second)
            {
                cout << "(" << neighbour.first << "," << neighbour.second << ")";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isUndirectedCyclicBfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (pair<int, int> nbr : adjList[frontNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = frontNode;
                }
                if (visited[nbr.first] && nbr.first != parent[frontNode])
                {
                    // cycle present
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g;

    // g.addEdge(srcNode, destNode, weight, direction);
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 2, 0);

    g.printAdjacencyList();

    bool ans = false;
    unordered_map<int, bool> visited;
    for (int i = 0; i < g.adjList.size(); i++)
    {
        if (!visited[i])
        {
            ans = g.isUndirectedCyclicBfs(i, visited);
            if (ans == true)
                break;
        }
    }

    if (ans == true)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle Absent" << endl;
    return 0;
}