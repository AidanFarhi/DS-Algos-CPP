#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void union_sets(int *nodes, int root1, int root2);
int find_root(int *nodes, int node);
int* initialize_node_list(int number_of_nodes);

// this is a weighted join that joins the smaller set to the larger one
void union_sets(int *nodes, int root1, int root2)
{
    if (nodes[root1] < nodes[root2]) // ex) -5 < -2 means -5 has 5 elements and is larger
    {
        nodes[root1] += nodes[root2]; // increase size of root1
        nodes[root2] = root1;         // set root2 to be root1's parent
    }
    else
    {
        nodes[root2] += nodes[root1]; // increase size of root2
        nodes[root1] = root2;         // set root1 to be root2's parent
    }
}

// this finds the parent or root of a given node
int find_root(int *nodes, int node)
{
    int x = node;
    while (nodes[x] > 0)
        x = nodes[x];
    return x;
}

// this creates an array to represent all nodes in heap of given size
int* initialize_node_list(int number_of_nodes)
{
    int *nodes = (int*) malloc(sizeof(int) * number_of_nodes + 1);
    for (int i = 0; i < number_of_nodes + 1; i++)
        nodes[i] = -1;
    return nodes;
}

// test client
int main()
{
    int *nodes = initialize_node_list(10);
    // create one disjoint set where 3 is the parent
    union_sets(nodes, 9, 3);
    union_sets(nodes, 3, 5);
    // now create another where 4 is the parent
    union_sets(nodes, 7, 4);
    union_sets(nodes, 8, 4);
    union_sets(nodes, 4, 10);
    // check that 3 is the parent of 9 and 5
    printf("Parent of 9: %d\n", find_root(nodes, 9));
    printf("Parent of 5: %d\n", find_root(nodes, 5));
    // check that 4 is the parent of 7, 8, and 10
    printf("Parent of 7: %d\n", find_root(nodes, 7));
    printf("Parent of 8: %d\n", find_root(nodes, 8));
    printf("Parent of 10: %d\n", find_root(nodes, 10));
    // now join the two subsets using 8 and 5
    union_sets(nodes, find_root(nodes, 8), find_root(nodes, 5));
    // check that 4 is the new parent of all the nodes
    printf("--------- After join ---------\n");
    printf("Parent of 3: %d\n", find_root(nodes, 3));
    printf("Parent of 9: %d\n", find_root(nodes, 9));
    printf("Parent of 5: %d\n", find_root(nodes, 5));
    printf("Parent of 7: %d\n", find_root(nodes, 7));
    printf("Parent of 8: %d\n", find_root(nodes, 8));
    printf("Parent of 10: %d\n", find_root(nodes, 10));
}