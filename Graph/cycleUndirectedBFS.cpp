#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Maintain Parent array to keep track of parent node of the current node
bool cycleBFS(int s, vector<int> adj[], vector<int> &visited, int n)
{
    // Initially all are set as -1 the after will be re-assigned with parent value
    vector<int> parent(n, -1);

    queue<int> q;
    visited[s] = 1;
    q.push(s);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (auto x : adj[temp])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push(x);
                parent[x] = temp;
            }
            else if (parent[temp] != x)
            {
                return true;
            }
        }
    }
    return false;
}

// Utility function to handle the disconnected graph
bool detectCycle(vector<int> adj[], int n)
{
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (cycleBFS(i, adj, visited, n))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n = 5;
    vector<int> adjList[n];

    // addEdge(adjList, 1, 0);
    // addEdge(adjList, 0, 2);
    // addEdge(adjList, 2, 1);
    // addEdge(adjList, 0, 3);
    // addEdge(adjList, 3, 4);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);

    if (detectCycle(adjList, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
