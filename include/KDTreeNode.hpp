
#ifndef KDTREENODE_HPP
#define KDTREENODE_HPP

using namespace std;

// Libraries
#include "Place.hpp"

// Clase KDTreeNode
class KDTreeNode
{
public:
    Place* data;
    KDTreeNode* left;
    KDTreeNode* right;

    // Constructor
    KDTreeNode(Place* _data)
        : data(_data), left(NULL), right(NULL)
    {}
};

#endif // KDTREENODE_HPP