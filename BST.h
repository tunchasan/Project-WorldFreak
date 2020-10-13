#ifndef BST_H
#define BST_H

#include <stdio.h>
#include "Node.h"

struct BST{

    // represent BST' root
    Node* root;
};

typedef struct BST BST;

// adds BST Nodes to the BST
Node* addNodeToBST(Node*);

// prints BST Nodes status
void printBST(Node*);

#endif