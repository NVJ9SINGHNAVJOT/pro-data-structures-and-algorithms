#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename T>

class Graph
{
public:
    // graph created with unordere_map
    // weight are integers only
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, bool direction, int weight)
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

    void bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            // insert neighbours
            for (pair<T, int> neighbour : adjList[frontNode])
            {
                if (!visited[neighbour.first])
                {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (pair<T, int> neighbour : adjList[src])
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
            for (pair<T, int> neighbour : node.second)
            {
                cout << "(" << neighbour.first << "," << neighbour.second << ")";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Graph<int> g;

    // g.addEdge(srcNode, destNode, weight, direction);
    g.addEdge(0, 1, 0, 0);
    g.addEdge(1, 3, 0, 0);
    g.addEdge(0, 2, 0, 0);
    g.addEdge(2, 4, 0, 0);

    g.printAdjacencyList();

    // run a loop for all nodes
    cout << "Printing BFS Traversal: " << endl;
    unordered_map<int, bool> visited;
    for (int i = 0; i < g.adjList.size(); i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }

    // run a loop for all nodes
    cout << endl;
    cout << "Printing DFS Traversal: " << endl;
    unordered_map<int, bool> visited2;
    for (int i = 0; i < g.adjList.size(); i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }

    // from single src node
    cout << endl;
    cout << "Printing BFS Traversal: " << endl;
    unordered_map<int, bool> visited3;
    g.bfs(3, visited3);

    return 0;
}