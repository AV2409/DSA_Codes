#include <iostream>
using namespace std;

#define V 4

bool isSafe(int v, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}
bool graphColoring(int graph[V][V], int m)
{
    int color[V] = {0};
    if (!graphColoringUtil(graph, m, color, 0))
    {
        cout << "Solution does not exist" << endl;
        return false;
    }
    cout << "Solution Exists: Following are the assigned colors: ";
    for (int i = 0; i < V; i++)
        cout << color[i] << " ";
    cout << endl;
    return true;
}
int main()
{
    int graph1[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m1 = 3;
    cout << "Graph 1:" << endl;
    graphColoring(graph1, m1);

    int graph2[V][V] = {{1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 1, 1, 1},
                        {1, 1, 1, 1}};
    int m2 = 3;
    cout << "Graph 2:" << endl;
    graphColoring(graph2, m2);
    return 0;
}
