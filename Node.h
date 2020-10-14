#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>

struct Node{

    // Represents Node' fields
    const char* word;

    int count;

    struct Node* rightChild;

    struct Node* leftChild;
};

typedef struct Node Node;

// creates a Node as default
Node* createNode();

#endif