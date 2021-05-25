#include <iostream>
using namespace std;

#ifndef Graph_h
#define Graph_h

/* Adjacency Matrix Representation of Graph */
class Graph
{
    public:
    int **m;
    int num_nodes;
    Graph(int n)
    {
        m = new int*[n+1];
        for (int i = 1; i <= n; i++) m[i] = new int[n+1];
        num_nodes = n;
    }
    void print_graph();
    void populate_graph();
};

void Graph::print_graph()
{
    cout << "   ";
    for (int i = 1; i <= num_nodes; i++) cout << i << "  ";
    cout << endl;
    for (int i = 1; i <= num_nodes; i++)
    {
        cout << i << " [";
        for (int j = 1; j <= num_nodes; j++)
        {
            if (j == num_nodes) cout << m[i][j];
            else cout << m[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}

void Graph::populate_graph()
{
    int num_edges, i, j;
    for (i = 1; i <= num_nodes; i++)
    {
        cout << "Enter the number of edges for node " << i << ": ";
        cin >> num_edges;
        for (j = 0; j < num_edges; j++)
        {
            int current;
            cout << "Enter a node that node " << i << " is connected to: ";
            cin >> current;
            m[i][current] = 1;
        }
    }
}

#endif