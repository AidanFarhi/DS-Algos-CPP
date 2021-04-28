#include <iostream>
using namespace std;

#ifndef TreeNodeCPP_h
#define TreeNodeCPP_h

template <class T>
class TreeNode
{
    public:
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode<T>(T val)
    {
        data = val;
        left = right = NULL;
    }
};

#endif