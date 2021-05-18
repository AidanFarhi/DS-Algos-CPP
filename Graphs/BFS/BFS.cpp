#include <iostream>
#include <queue>
using namespace std;

/**
 * This is Breadth First Search using an Adjacency Matrix representation of a graph
 */

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