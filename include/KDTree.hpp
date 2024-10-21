
#ifndef KDTREE_HPP
#define KDTREE_HPP

using namespace std;

// Libraries
#include <vector>
#include "KDTreeNode.hpp"

class KDTree
{
public:
    KDTreeNode* root;

    // Constructor
    KDTree();

    // Destructor
    ~KDTree();

    // Métodos
    void buildTree(vector<Place*>& places);
    KDTreeNode* buildTreeRec(vector<Place*>& places, int depth, int start, int end);
    void nearestNeighbor(KDTreeNode* node, Place* target, int depth, KDTreeNode*& best, float& bestDist);
    void destroyTree(KDTreeNode* node);
};

#endif // KDTREE_HPP