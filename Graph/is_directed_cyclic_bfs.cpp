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

    bool isDirectedCyclicbfs()
    {
        int count = 0;
        queue<int> q;
        unordered_map<int, int> inDegree;

        // indegree calculation
        for (auto &node : adjList)
        {
            for (pair<int, int> nbr : node.second)
            {
                inDegree[nbr.first]++;
            }
        }

        // put all nodes inside queue, which has indegree == 0
        for (auto &node : adjList)
        {
            if (inDegree[node.first] == 0)
            {
                q.push(node.first);
            }
        }

        // bfs logic
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();
            count++;

            for (pair<int, int> nbr : adjList[fNode])
            {
                inDegree[nbr.first]--;
                // check again for zero indegree for nbr
                if (inDegree[nbr.first] == 0)
                {
                    q.push(nbr.first);
                }
            }
        }

        return adjList.size() != count;
    }
};

int main()
{
    Graph g;

    // g.addEdge(srcNode, destNode, direction, weight);
    g.addEdge(0, 1, 1, 1);
    g.addEdge(1, 2, 1, 1);
    g.addEdge(2, 3, 1, 1);
    g.addEdge(3, 4, 1, 1);
    g.addEdge(4, 5, 1, 1);
    g.addEdge(5, 2, 1, 1);

    g.printAdjacencyList();

    if (g.isDirectedCyclicbfs() == true)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle Absent" << endl;

    return 0;
}

// 5-> 2,
// 4-> 5,
// 3-> 4,
// 2-> 3,
// 1-> 2,
// 0-> 1,
// fNode: 0 nbr: 1nbr indegree: 0
// fNode: 1 nbr: 2nbr indegree: 1
// topological sort
// 0, 1,