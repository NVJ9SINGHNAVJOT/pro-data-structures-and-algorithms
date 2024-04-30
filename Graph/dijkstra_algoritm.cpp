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
#include <set>
using namespace std;
;

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

    void shortestPathDijkstra(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;

        // intiial steps
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // fetch the smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin());

            // neighbour traverse
            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    // distance update krna hai
                    // finding entry in set
                    auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                    // if found, then remove
                    if (result != st.end())
                    {
                        st.erase(result);
                    }
                    // updation in dist array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }

        cout << "printing ans:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << ", ";
        }
        cout << endl;
    }
};

int main()
{
    Graph g1;
    // g1.addEdge(srcNode, destNode, direction, weight);
    g1.addEdge(5, 4, 0, 6);
    g1.addEdge(5, 6, 0, 9);
    g1.addEdge(6, 3, 0, 2);
    g1.addEdge(6, 1, 0, 14);
    g1.addEdge(6, 3, 0, 6);
    g1.addEdge(1, 3, 0, 9);
    g1.addEdge(1, 2, 0, 7);
    g1.addEdge(3, 4, 0, 11);
    g1.addEdge(3, 2, 0, 10);
    g1.addEdge(2, 4, 0, 15);

    cout << endl;
    g1.printAdjacencyList();

    // 1 is added because nodes start form 1 not 0
    g1.shortestPathDijkstra(6, g1.adjList.size() + 1);

    return 0;
}