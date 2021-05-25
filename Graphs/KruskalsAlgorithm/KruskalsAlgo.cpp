#include <iostream>
#include "UnionFind.h"
using namespace std;
#define I INT_MAX

// global test edges array
int edges[3][9] = {
    {1, 1,  2,  2, 3,  4,  4,  5,  5},
    {2, 6,  3,  7, 4,  5,  7,  6,  7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};

/**
 * This is Kruskals Algorithm for finding the minimum cost spanning tree
 * of a weighted graph.
 */
void KruskalsAlgorithm(int num_nodes, int num_edges)
{
    int i = 0, j, k, u, v, min;
    int included[num_edges];
    for (j = 0; j < num_edges; j++) included[j] = 0;
    int result[2][num_nodes-1];
    UnionFind *set = new UnionFind(num_nodes);
    while (i < num_nodes - 1)
    {
        min = I;
        for (j = 0; j < num_edges; j++) // find min cost edge
        {
            if (included[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }
        // find out if nodes are already connected
        if (set->Find(u) != set->Find(v)) 
        {
            result[0][i] = u;
            result[1][i] = v;
            set->Union(set->Find(u), set->Find(v));
            i++;
        }
        included[k] = 1; // mark node as included
    }

    // print results
    for (i = 0; i < num_nodes-1; i++)
        cout << "(" << result[0][i] << "," << result[1][i] << ")" << endl;
}

int main()
{
    KruskalsAlgorithm(7, 9);
}