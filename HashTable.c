#include "HashTable.h"

HashNode** createHashTable(){

    HashNode** hashTable = (HashNode**)malloc(26 * sizeof(HashNode*));

    int i;

    int asciiCursor = 97;

    for(i = 0; i < 26; i++){

        BST* newBST = NULL;

        // Initialize hashTable's index
        hashTable[i] = createHashNode((char)asciiCursor, newBST);

        asciiCursor++;
    }

    return hashTable;
}

HashNode* createHashNode(char letter, BST* BSTRoot){
    HashNode* hashNode = (HashNode*)malloc(sizeof(HashNode));
    // Assing according fields to hashNode's fields
    hashNode->letter = letter;
    hashNode->root = NULL;

    return hashNode;
}