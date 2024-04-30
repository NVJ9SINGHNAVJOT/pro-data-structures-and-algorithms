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
};

int main()
{
    Graph g1;
    // g1.addEdge(srcNode, destNode, direction, weight);
    g1.addEdge(0, 1, 1, 5);
    g1.addEdge(1, 2, 1, 8);
    g1.addEdge(0, 2, 1, 6);
    cout << endl;
    g1.printAdjacencyList();

    Graph g2;
    g2.addEdge(0, 1, 1, 1);
    g2.addEdge(1, 2, 1, 1);
    g2.addEdge(0, 2, 1, 1);
    cout << endl;
    g2.printAdjacencyList();

    return 0;
}