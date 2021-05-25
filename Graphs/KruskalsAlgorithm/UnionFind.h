using namespace std;

#ifndef UnionFind_h
#define UnionFind_h

class UnionFind
{
    public:
    int *nodes;
    void Union(int u, int v);
    int Find(int node);
    UnionFind(int num_nodes);
};

UnionFind::UnionFind(int num_nodes)
{
    nodes = new int[num_nodes+1];
    for (int i = 0; i <= num_nodes; i++)
        nodes[i] = -1;
}

// this is a weighted join that joins the smaller set to the larger one
void UnionFind::Union(int u, int v)
{
    if (nodes[u] < nodes[v]) // ex) -5 < -2 means -5 has 5 elements and is larger
    {
        nodes[u] += nodes[v]; // increase size of u
        nodes[v] = u;         // set v to be u's parent
    }
    else
    {
        nodes[v] += nodes[u]; // increase size of v
        nodes[u] = v;         // set u to be v's parent
    }
}

// this finds the parent or root of a given node
int UnionFind::Find(int node)
{
    int x = node;
    while (nodes[x] > 0)
        x = nodes[x];
    return x;
}

#endif