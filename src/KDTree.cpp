using namespace std;

// Libraries
#include <algorithm>
#include <cmath>

// Headers
#include "../include/KDTree.hpp"

/*
    Constructor
    ------------------------------------------------------------------------------
*/
KDTree::KDTree()
    : root(NULL)
{}

/*
    Destructor 
    ------------------------------------------------------------------------------
*/
KDTree::~KDTree()
{
    destroyTree(root);
}

/*
    Destructor Node
    ------------------------------------------------------------------------------
*/
void KDTree::destroyTree(KDTreeNode* node)
{
    if (node != NULL)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

/*
    Constructor with a vector
    ------------------------------------------------------------------------------
*/
void KDTree::buildTree(vector<Place*>& places)
{
    root = buildTreeRec(places, 0, 0, places.size());
}

/*
    Recursive constructor
    ------------------------------------------------------------------------------
*/
KDTreeNode* KDTree::buildTreeRec(vector<Place*>& places, int depth, int start, int end)
{
    if (start >= end)
    {
        return NULL;
    }

    int axis = depth % 2;

    // Sortplaces
    sort(places.begin() + start, places.begin() + end, [axis](Place* a, Place* b)
    {
        if (axis == 0)
            return a->getX() < b->getX();
        else
            return a->getY() < b->getY();
    });

    int mid = (start + end) / 2;
    KDTreeNode* node = new KDTreeNode(places[mid]);

    node->left = buildTreeRec(places, depth + 1, start, mid);
    node->right = buildTreeRec(places, depth + 1, mid + 1, end);

    return node;
}

/*
    NPD  equivalente - Nearest Neighbour
    ------------------------------------------------------------------------------
*/
void KDTree::nearestNeighbor(KDTreeNode* node, Place* target, int depth, KDTreeNode*& best, float& bestDist)
{
    if (node == NULL)
    {
        return;
    }

    // Avoid compare with himself
    if (node->data != target)
    {
        float dist = sqrt(pow(node->data->getX() - target->getX(), 2) + pow(node->data->getY() - target->getY(), 2));

        if (dist < bestDist)
        {
            bestDist = dist;
            best = node;
        }
    }

    int axis = depth % 2;

    // Decide branch to explore
    KDTreeNode* nextBranch = NULL;
    KDTreeNode* oppositeBranch = NULL;

    if ((axis == 0 && target->getX() < node->data->getX()) || (axis == 1 && target->getY() < node->data->getY()))
    {
        nextBranch = node->left;
        oppositeBranch = node->right;
    }
    else
    {
        nextBranch = node->right;
        oppositeBranch = node->left;
    }

    // Travel the best branch
    nearestNeighbor(nextBranch, target, depth + 1, best, bestDist);

    //  Verification for the other branch
    float axisDist = (axis == 0) ? fabs(target->getX() - node->data->getX()) : fabs(target->getY() - node->data->getY());

    if (axisDist < bestDist)
    {
        nearestNeighbor(oppositeBranch, target, depth + 1, best, bestDist);
    }
}