#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

void insertAtBottom(stack<int> &s, int target)
{

    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    // rec cal
    insertAtBottom(s, target);
    // BT
    s.push(topElement);
}

void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    int target = s.top();
    s.pop();

    // reverse stack
    reverseStack(s);
    // insert at bottom target ko
    insertAtBottom(s, target);
}

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

    // graph should be directed acyclic
    void topSortBfs(stack<int> &topoSort)
    {
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
            topoSort.push(fNode);

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
    }

    void shortestPathDfs(int dest, int n)
    {
        stack<int> topoOrder;
        topSortBfs(topoOrder);
        reverseStack(topoOrder);

        vector<int> dist(n, INT_MAX);

        // source
        int src = topoOrder.top();
        topoOrder.pop();

        dist[src] = 0;

        // 0 is source node
        for (auto nbr : adjList[0])
        {
            if (dist[0] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while (!topoOrder.empty())
        {
            int topElement = topoOrder.top();
            topoOrder.pop();

            if (dist[topElement] != INT_MAX)
            {
                for (auto nbr : adjList[topElement])
                {
                    if (dist[topElement] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout << "Printing ans: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "-> " << dist[i] << endl;
        }
    }

    // with source node
    void shortestPathDfs(int src, int dest, int n)
    {
        stack<int> topoOrder;
        topSortBfs(topoOrder);
        reverseStack(topoOrder);

        vector<int> dist(n, INT_MAX);

        // source node-> pop topopOrder till source node is not found
        while (src != topoOrder.top())
        {
            topoOrder.pop();
        }

        cout << src << endl;
        topoOrder.pop();

        dist[src] = 0;

        // 0 is source node
        for (auto nbr : adjList[src])
        {
            if (dist[src] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[src] + nbr.second;
            }
        }

        while (!topoOrder.empty())
        {
            int topElement = topoOrder.top();
            topoOrder.pop();

            if (dist[topElement] != INT_MAX)
            {
                for (auto nbr : adjList[topElement])
                {
                    if (dist[topElement] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        cout << "Printing ans: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "-> " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g1;
    // g1.addEdge(srcNode, destNode, weight, direction);
    g1.addEdge(0, 1, 1, 5);
    g1.addEdge(0, 2, 1, 3);
    g1.addEdge(1, 3, 1, 3);
    g1.addEdge(2, 1, 1, 2);
    g1.addEdge(2, 4, 1, 6);
    g1.addEdge(2, 3, 1, 5);
    g1.addEdge(4, 3, 1, 1);

    g1.printAdjacencyList();

    g1.shortestPathDfs(0, 3, g1.adjList.size() + 1);

    return 0;
}
