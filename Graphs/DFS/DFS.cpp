#include <iostream>
#include "Graph.h"
using namespace std;

/**
 * This is Depth First Search using an Adjacency Matrix representation of a graph
 */

/* Function Prototypes */
void DFS(Graph *graph);
void DFS_helper(int **graph, int *visited, int u, int n);

/* This is a recursive implementation of DFS */
void DFS(Graph *graph)
{
    int start;
    cout << "Enter a node to start DFS on: ";
    cin >> start;
    int visited[graph->num_nodes+1];
    for (int i = 1; i <= graph->num_nodes; i++) visited[i] = 0;
    // This is where we make the initial call
    DFS_helper(graph->m, visited, start, graph->num_nodes);
}

void DFS_helper(int **graph, int *visited, int u, int n)
{
    if (visited[u] == 0)
    {
        cout << u << " ";
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (graph[u][v] == 1 && visited[v] == 0)
                DFS_helper(graph, visited, v, n);
        }
    }
}

/* Test Client */
int main()
{
    int n;
    cout << "Enter number of nodes in graph: ";
    cin >> n;
    Graph *graph = new Graph(n);
    graph->populate_graph();
    graph->print_graph();
    DFS(graph);
}