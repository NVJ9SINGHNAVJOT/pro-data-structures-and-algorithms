#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    // graph created with unordere_map
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

    bool isUndirectedCyclicDfs(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (pair<int, int> nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                bool checkAageKaAns = isUndirectedCyclicDfs(nbr.first, visited, src);
                if (checkAageKaAns == true)
                    return true;
            }
            if (visited[nbr.first] && nbr.first != parent)
            {
                // cycle present
                return true;
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
    g.addEdge(1, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(4, 6, 0);
    g.addEdge(5, 6, 0);

    g.printAdjacencyList();

    cout << endl;
    unordered_map<int, bool> visited1;
    g.dfs(3, visited1);
    cout << endl;
    unordered_map<int, bool> visited2;
    g.bfs(3, visited2);
    cout << endl;

    bool ans = false;
    unordered_map<int, bool> visited;
    for (int i = 0; i < g.adjList.size(); i++)
    {
        if (!visited[i])
        {
            ans = g.isUndirectedCyclicDfs(i, visited, -1);
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