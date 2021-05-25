#include <iostream>
#include <queue>
#include "Graph.h"
using namespace std;

/**
 * This is Breadth First Search using an Adjacency Matrix representation of a graph
 */

/**
 *  This an iterative BFS implementation using a Queue
 */
void BFS(Graph* graph)
{
    queue<int> q;
    int visited[graph->num_nodes+1];
    for (int i = 1; i <= graph->num_nodes; i++) 
    {
        visited[i] = 0;
    }
    int start;
    cout << "Node to start search from: ";
    cin >> start;
    q.push(start);
    visited[start] = 1;
    cout << start << " ";
    while (!q.empty())
    {
        int n = q.front();
        for (int v = 1; v <= graph->num_nodes; v++)
        {
            if (graph->m[n][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                q.push(v);
                visited[v] = 1;
            }
        }
        q.pop();
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes in graph: ";
    cin >> n;
    Graph *graph = new Graph(n);
    graph->populate_graph();
    graph->print_graph();
    BFS(graph);
}