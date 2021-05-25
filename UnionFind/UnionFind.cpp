#include <iostream>
using namespace std;

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

int main()
{
    UnionFind* UF = new UnionFind(10);
    // create one disjoint set where 3 is the parent
    UF->Union(9, 3);
    UF->Union(3, 5);
    // now create another where 4 is the parent
    UF->Union(7, 4);
    UF->Union(8, 4);
    UF->Union(4, 10);
    // check that 3 is the parent of 9 and 5
    cout << "Parent of 9: " << UF->Find(9) << endl;
    cout << "Parent of 5: " << UF->Find(5) << endl;
    // check that 4 is the parent of 7, 8, and 10
    cout << "Parent of 7: " << UF->Find(7) << endl;
    cout << "Parent of 8: " << UF->Find(8) << endl;
    cout << "Parent of 10: " << UF->Find(10) << endl;
    // now join the two subsets using 8 and 5
    UF->Union(UF->Find(8), UF->Find(5));
    // check that 4 is the new parent of all the nodes
    cout << "--------- After Join ---------" << endl;
    cout << "Parent of 3: " << UF->Find(3) << endl;
    cout << "Parent of 9: " << UF->Find(9) << endl;
    cout << "Parent of 5: " << UF->Find(5) << endl;
    cout << "Parent of 7: " << UF->Find(7) << endl;
    cout << "Parent of 8: " << UF->Find(8) << endl;
    cout << "Parent of 10: " << UF->Find(10) << endl;
}