#include <iostream>
using namespace std;

void addEdge(int **A, int u, int v)
{
    A[u][v] = 1;
    A[v][u] = 1; // By simply removing this line DIRECTED graph can be represented
}

void printGraph(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;

    // Create a 2D Dynamic Array/Matrix
    int **adjMat = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        adjMat[i] = new int[n];
    }

    // Initialize matrix to zero values
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            adjMat[i][j] = 0;
        }
    }

    addEdge(adjMat, 0, 1);
    addEdge(adjMat, 0, 4);
    addEdge(adjMat, 1, 2);
    addEdge(adjMat, 1, 3);
    addEdge(adjMat, 1, 4);
    addEdge(adjMat, 2, 3);
    addEdge(adjMat, 3, 4);

    printGraph(adjMat, n);

    return 0;
}
