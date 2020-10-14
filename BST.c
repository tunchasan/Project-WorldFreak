#include "BST.h"

BST* createBSTNode(){
    // allocates new BST
    BST* newBST = (BST*)malloc(sizeof(BST));
    
    newBST->root = NULL;

    return newBST;
}