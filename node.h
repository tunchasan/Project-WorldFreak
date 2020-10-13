#ifndef NODE_H
#define NODE_H

struct Node{

    // Represents Node' fields
    char* word;

    int count;

    struct Node* rightChild;

    struct Node* leftChild;

    // creates a BST as default
    Node* createNode();
};

typedef struct Node Node;

#endif