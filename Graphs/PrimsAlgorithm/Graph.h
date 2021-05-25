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
    int num_edges;
    Graph(int n);
    void print_graph();
    void populate_graph();
};

Graph::Graph(int n)
{
    int i, j;
    m = new int*[n+1];
    for (i = 1; i <= n; i++) 
        m[i] = new int[n+1];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            m[i][j] = INT_MAX;
    num_nodes = n;
}

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
            if (j == num_nodes) 
            {
                if (m[i][j] != INT_MAX)
                {
                    cout << m[i][j];
                }
                else
                {
                    cout << "0";
                }
            }
            else
            {
                if (m[i][j] != INT_MAX)
                {
                    cout << m[i][j] << ", ";;
                }
                else
                {
                    cout << "0, ";
                }
            }
        }
        cout << "]" << endl;
    }
}

void Graph::populate_graph()
{
    int current_n_edges, i, j;
    for (i = 1; i <= num_nodes; i++)
    {
        cout << "Enter the number of edges for node " << i << ": ";
        cin >> current_n_edges;
        num_edges += current_n_edges;   
        for (j = 0; j < current_n_edges; j++)
        {
            int current;
            int weight;
            cout << "Enter a node that node " << i << " is connected to: ";
            cin >> current;
            cout << "Enter weight of edge from " << i << " to " << current << ": ";
            cin >> weight;
            m[i][current] = weight;
        }
    }
}

#endif