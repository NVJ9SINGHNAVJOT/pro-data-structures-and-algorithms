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

    void bellmanFordAlgo(int n, int src)
    {
        // assuming directed weighted graph
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // n-1 relaxation step
        for (int i = 0; i < n - 1; i++)
        {
            // for all edges
            for (auto t : adjList)
            {
                for (auto nbr : t.second)
                {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // to check for -ve cycle
        bool negativeCycle = false;
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    negativeCycle = true;
                    break;
                }
            }
            if (negativeCycle)
            {
                break;
            }
        }

        if (negativeCycle == true)
            cout << "-ve cycle present" << endl;
        else
            cout << "-ve cycle absent" << endl;

        cout << "printing dist array: ";
        for (auto i : dist)
            cout << i << " ";
    }
};

int main()
{
    Graph g1;
    // g1.addEdge(srcNode, destNode, direction, weight);

    // g1.addEdge(0, 1, 1, -1);
    // g1.addEdge(0, 2, 1, 4);
    // g1.addEdge(1, 2, 1, 3);
    // g1.addEdge(1, 3, 1, 2);
    // g1.addEdge(1, 4, 1, 2);
    // g1.addEdge(3, 2, 1, 5);
    // g1.addEdge(3, 1, 1, 1);
    // g1.addEdge(4, 3, 1, -3);

    // g1.printAdjacencyList();
    // g1.bellmanFordAlgo(5, 0);

    Graph g2;

    g2.addEdge(3, 0, 1, 4);  // D -> A, weight 4
    g2.addEdge(3, 2, 1, 7);  // D -> C, weight 7
    g2.addEdge(3, 4, 1, 3);  // D -> E, weight 3
    g2.addEdge(0, 2, 1, 4);  // A -> C, weight 4
    g2.addEdge(2, 0, 1, -9); // C -> A, weight -9
    g2.addEdge(0, 4, 1, 5);  // A -> E, weight 5
    g2.addEdge(4, 2, 1, 3);  // E -> C, weight 3
    g2.addEdge(1, 2, 1, -4); // B -> C, weight -4
    g2.addEdge(4, 1, 1, 2);  // E -> B, weight 2

    g2.printAdjacencyList();
    g2.bellmanFordAlgo(5, 0);

    cout << endl;

    Graph g3;
    g3.addEdge(3, 0, 1, 4);  // D -> A, weight 4
    g3.addEdge(3, 2, 1, 7);  // D -> C, weight 7
    g3.addEdge(3, 4, 1, 3);  // D -> E, weight 3
    g3.addEdge(0, 2, 1, 4);  // A -> C, weight 4
    g3.addEdge(2, 0, 1, -3); // C -> A, weight -3
    g3.addEdge(0, 4, 1, 5);  // A -> E, weight 5
    g3.addEdge(4, 2, 1, 3);  // E -> C, weight 3
    g3.addEdge(1, 2, 1, -4); // B -> C, weight -4
    g3.addEdge(4, 1, 1, 2);  // E -> B, weight 2

    g3.printAdjacencyList();
    g3.bellmanFordAlgo(5, 0);

    return 0;
}
