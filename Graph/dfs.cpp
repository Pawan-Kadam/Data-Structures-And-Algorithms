#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

// Recursive DFS
void dfsRecursive(int s, vector<int> adj[], vector<int> &visited)
{
    visited[s] = 1;
    cout << s << " ";

    for (auto x : adj[s])
    {
        if (!visited[x])
        {
            dfsRecursive(x, adj, visited);
        }
    }
}

// Iterative DFS
// Similar to BFS just replace queue by stack
void dfsIterative(int s, vector<int> adj[], vector<int> &visited)
{
    stack<int> st;
    visited[s] = 1;
    st.push(s);

    while (!st.empty())
    {
        int temp = st.top();
        st.pop();

        cout << temp << " ";

        for (auto x : adj[temp])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                st.push(x);
            }
        }
    }
}

// To handle the situation of disconnected graphs
void disconDFS(vector<int> adj[], int n)
{
    vector<int> visited(n, 0);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfsRecursive(i, adj, visited);
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
    int n = 7;
    vector<int> adjList[n];

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 5, 4);
    addEdge(adjList, 5, 6);
    addEdge(adjList, 4, 6);

    printGraph(adjList, n);

    disconDFS(adjList, n);

    return 0;
}
