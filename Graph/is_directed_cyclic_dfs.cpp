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

    bool isDirectedCyclicDfs(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                bool ans = isDirectedCyclicDfs(nbr.first, visited, dfsVisited);
                if (ans == true)
                {
                    return true;
                }
            }
            if (visited[nbr.first == true] && dfsVisited[nbr.first] == true)
            {
                return true;
            }
        }

        dfsVisited[src] = false;
        return false;
    }
};

int main()
{
    Graph g;

    // g.addEdge(srcNode, destNode, weight, direction);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 2, 1);

    g.printAdjacencyList();

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 0; i < g.adjList.size(); i++)
    {
        if (!visited[i])
        {
            ans = g.isDirectedCyclicDfs(i, visited, dfsVisited);
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