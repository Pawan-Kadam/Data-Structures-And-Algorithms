#include <bits/stdc++.h>
using namespace std;

// Function to create Adjancency List for Non-Weighted Graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // By simply removing this line DIRECTED graph can be represented

    // For weighted replace by
    // adj[u].push_back({v, wt});
}

// Function to print Adjancency List for Non-Weighted Graph
void printGraph(vector<int> A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "  -->  ";
        for (int x : A[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;

    vector<int> adjList[n + 1];

    // For weighted replace by
    // vector<pair<int, int>> adjList[n + 1];

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    printGraph(adjList, n);

    return 0;
}
