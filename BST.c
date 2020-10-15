#include "BST.h"

BST* createBSTNode(){
    // allocates new BST
    BST* newBST = (BST*)malloc(sizeof(BST));

    newBST->root = NULL;

    return newBST;
}

Node* addNodeToBST(Node* root, const char* word){
    
    // If the tree is empty
    if(root == NULL){
        // creates new node
        Node* newNode = createNode();
        // assings given word to newNode's word
        newNode->word = word;

        root = newNode;

        return root;
    }

    // If the given word is greater than root's word
    if(strcmp(word, root->word) > 0){
        root->rightChild = addNodeToBST(root->rightChild, word);
    }

    // If the given word is equal to root's word
    else if(strcmp(word, root->word) == 0){
        root->count = root->count + 1;
    }

    // If the given word is less than root's word
    else if(strcmp(word, root->word) < 0){
        root->leftChild = addNodeToBST(root->leftChild, word);
    }

    return root;
}

void printBST(Node* root){
    if(root == NULL){
        return;
    }

    printBST(root->leftChild);

    // EXTRA TODO -> sprintf
    printf("%-15s: %5d\n", root->word, root->count);

    // TODO
    // Write content to "output.txt"

    printBST(root->rightChild);
}