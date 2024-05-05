#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
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
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
            {
                cout << "(" << neighbour.first << "," << neighbour.second << "), ";
            }
            cout << endl;
        }
    }

    void floydWarshall(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // diagonal pr zero mark krdo
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        // graph k according dist insert krdia h
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }

        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int dest = 0; dest < n; dest++)
                {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
            cout << "Printing distance array: for helper node  " << helper << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << dist[i][j] << ", ";
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph g;
    // g1.addEdge(srcNode, destNode, direction, weight);

    g.addEdge(0, 1, 1, 3);
    g.addEdge(0, 3, 1, 5);
    g.addEdge(1, 0, 1, 2);
    g.addEdge(1, 3, 1, 4);
    g.addEdge(2, 1, 1, 1);
    g.addEdge(3, 2, 1, 2);
    g.printAdjacencyList();

    g.floydWarshal(4);
    return 0;
}
