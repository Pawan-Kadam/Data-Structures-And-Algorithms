#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Iterative DFS
bool bipartiteDFSIterative(int s, vector<int> adj[], vector<int> &color)
{
    stack<int> st;
    st.push(s);

    while (!st.empty())
    {
        int temp = st.top();
        st.pop();

        for (auto x : adj[temp])
        {
            if (color[x] == -1)
            {
                color[x] = 1 - color[temp];
                st.push(x);
            }
            else if (color[temp] == color[x])
            {
                return false;
            }
        }
    }
    return true;
}

// Recursive DFS
bool bipartiteDFSRecursive(int s, vector<int> adj[], vector<int> &color)
{
    for (auto x : adj[s])
    {
        if (color[x] == -1)
        {
            color[x] = 1 - color[s];
            if (!bipartiteDFSRecursive(x, adj, color))
            {
                return false;
            }
        }
        else if (color[s] == color[x])
        {
            return false;
        }
    }
    return true;
}

// Utility function to handle disconnected graph
bool checkBipartite(vector<int> adj[], int n)
{
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            // if (!bipartiteDFSIterative(i, adj, color))
            // {
            //     return false;
            // }

            if (!bipartiteDFSRecursive(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 7;
    vector<int> adjList[n];

    // addEdge(adjList, 1, 2);
    // addEdge(adjList, 2, 3);
    // addEdge(adjList, 3, 4);
    // addEdge(adjList, 4, 5);
    // addEdge(adjList, 5, 6);
    // addEdge(adjList, 6, 1);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 5, 4);
    addEdge(adjList, 5, 6);
    addEdge(adjList, 4, 6);

    if (checkBipartite(adjList, n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
