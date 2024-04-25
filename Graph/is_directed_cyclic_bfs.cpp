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
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
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

    bool isDirectedCyclicbfs()
    {
        int count = 0;
        queue<int> q;
        unordered_map<int, int> inDegree;

        // indegree calculation
        for (auto &node : adjList)
        {
            for (int nbr : node.second)
            {
                inDegree[nbr]++;
            }
        }

        // put all nodes inside queue, which has indegree == 0
        for (auto node : adjList)
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

            for (int nbr : adjList[fNode])
            {
                inDegree[nbr]--;
                // check again for zero indegree for nbr
                if (inDegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        return adjList.size() != count;
    }
};

int main()
{
    Graph g;

    // g.addEdge(srcNode, destNode, direction);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 2, 1);

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