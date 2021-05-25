#include <iostream>
#include "Graph.h"
#include "set"
#define I INT_MAX
using namespace std;

/**
 * This is Prims Algorithm for finding the minimum cost spanning tree in a weighted graph.
 */

void PrimsAlgo(Graph *graph)
{
    set<int> in_tree;
    int total_cost = 0;
    int tree_nodes[graph->num_nodes];
    int tree_nodes_i = 2;
    // first find min edge in tree
    int u, v, min = I;
    for (int i = 1; i <= graph->num_nodes; i++)
    {
        for (int j = i; j <= graph->num_nodes; j++)
        {
            if (graph->m[i][j] < min)
            {
                u = i;
                v = j;
                min = graph->m[i][j];
            }
        }    
    }
    // set the initial tree edges
    tree_nodes[0] = u;
    tree_nodes[1] = v;
    total_cost += graph->m[u][v];
    in_tree.insert(u);
    in_tree.insert(v);
    // now build the spanning tree
    int u_min, v_min, new_u, new_v;
    new_u = u;
    new_v = v;
    int new_cost;
    for (int i = 1; i <= graph->num_nodes; i++)
    {
        u_min = v_min = I;
        new_cost = 0;
        // first find min edge connected to u
        for (int j = 1; j <= graph->num_nodes; j++)
        {
            if (graph->m[u][j] < u_min && in_tree.find(j) == in_tree.end())
            {
                u_min = graph->m[u][j];
                new_u = j;
                new_cost = graph->m[u][j];
            }
        }
        // now find min edge connected to v
        for (int k = 1; k <= graph->num_nodes; k++)
        {
            if (graph->m[v][k] < v_min && in_tree.find(k) == in_tree.end())
            {
                v_min = graph->m[v][k];
                new_v = k;
                new_cost = graph->m[v][k];
            }
        }
        // now add new edges to spanning tree and add edges to in_tree
        if (u_min < v_min)
        {
            if (new_u != u)
            {
                tree_nodes[tree_nodes_i++] = new_u;
                in_tree.insert(new_u);
                u = new_u;
            }
        }
        else
        {
            if (new_v != v)
            {
                tree_nodes[tree_nodes_i++] = new_v;
                in_tree.insert(new_v);
                v = new_v;
            }
        }
        total_cost += new_cost;
    }
    // print results
    for (int t = 0; t < graph->num_nodes; t++)
        cout << tree_nodes[t] << "->";
    cout << "end" << endl;
    cout << "Total cost: " << total_cost << endl;
}

/* Test Client */
int main()
{
    int test_graph[8][8] = {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}
    };
    // int n;
    // cout << "Enter number of nodes in graph: ";
    // cin >> n;
    Graph *graph = new Graph(7);
    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= 7; j++)
            graph->m[i][j] = test_graph[i][j];
    // graph->populate_graph();
    graph->print_graph();
    PrimsAlgo(graph);
}
