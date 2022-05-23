#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Iterative DFS using stack (Similar to BFS just replace queue with stack)
bool cycleDFSIterative(int s, vector<int> adj[], vector<int> &visited, int n)
{
    vector<int> parent(n, -1);
    stack<int> st;
    st.push(s);

    while (!st.empty())
    {
        int temp = st.top();
        st.pop();

        for (auto x : adj[temp])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                st.push(x);
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

// Recursive DFS
bool cycleDFSRecursive(int s, int parent, vector<int> adj[], vector<int> &visited)
{
    for (auto x : adj[s])
    {
        if (!visited[x])
        {
            visited[x] = 1;
            if (cycleDFSRecursive(x, s, adj, visited))
            {
                return true;
            }
        }
        else if (parent != x)
        {
            return true;
        }
    }
    return false;
}

bool detectCycle(vector<int> adj[], int n)
{
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            // if (cycleDFSIterative(i, adj, visited, parent))
            // {
            //     return true;
            // }

            if (cycleDFSRecursive(i, -1, adj, visited))
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
