#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

struct BST{

    // represent BST' root
    Node* root;
};

typedef struct BST BST;

// creates BST Node
BST* createBSTNode();

// adds BST Nodes to the BST
Node* addNodeToBST(Node*);

// prints BST Nodes status
void printBST(Node*);

#endif