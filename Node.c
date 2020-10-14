#include "Node.h"

Node* createNode(){
    // creates new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->count = 1;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->word = "";
}