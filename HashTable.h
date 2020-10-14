#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <stdio.h>
#include "Node.h"
#include "BST.h"

struct HashNode{

    // Represents the root of a Bst that starts with "letter"
    Node* root;

    char letter;
};

typedef struct HashNode HashNode;

// Creates hash table
HashNode** createHashTable();

// Creates hash table's node 
HashNode* createHashNode(char, BST*);

#endif