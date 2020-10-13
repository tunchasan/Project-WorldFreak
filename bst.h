#ifndef BST_H
#define BST_H

#include <stdio.h>
#include "node.h"

struct BST{

    // represent BST' root
    Node* root = NULL;

    // adds BST Nodes to the BST
    Node* addNodeToBST(Node*);

    // prints BST Nodes status
    void printBST(Node*);

};

typedef struct BST BST;

#endif