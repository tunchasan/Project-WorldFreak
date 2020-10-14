#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

struct BST{

    // represent BST' root
    Node* root;
};

typedef struct BST BST;

// creates BST Node
BST* createBSTNode();

// adds BST Nodes to the BST
Node* addNodeToBST(Node*, const char*);

// prints BST Nodes status as inorder traversal
void printBST(Node*);

#endif