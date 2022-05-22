#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void bfs(int s, vector<int> adj[], vector<int> &visited)
{
    queue<int> q;
    visited[s] = 1;
    q.push(s);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";

        for (auto x : adj[temp])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}

// To handle the situation of disconnected graphs
void disconBFS(vector<int> adj[], int n)
{
    vector<int> visited(n, 0);

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            bfs(i, adj, visited);
        }
    }
}

void printGraph(vector<int> adjList[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << i << " --> ";
        for (auto x : adjList[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    vector<int> adjList[n];

    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    printGraph(adjList, n);

    disconBFS(adjList, n);

    return 0;
}
