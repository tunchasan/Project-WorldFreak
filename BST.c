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

void printBST(Node* root, int fileNo, int maxWordLength){
    if(root == NULL){
        return;
    }

    printBST(root->leftChild, fileNo, maxWordLength);

    // Alling and print the data to "output.txt"
    allignText(root->word, root->count, fileNo, maxWordLength);

    printBST(root->rightChild, fileNo, maxWordLength);
}

void allignText(const char* text, int count, int fileNo, int maxWordLength){

    // counter
    int i;
    int counter = 0;

    char line[200];

    for(i = 0; i < 200; i++)
       line[i] = ' ';

    for(i = 0; i < maxWordLength; i++){
        line[i] = text[i];
    }

    // for(i = strlen(text); i < maxWordLength + 1; i++){
    //     line[i] = ' ';
    // }

    // line[maxWordLength + 1] = ':';
    // line[maxWordLength + 2] = ' ';

    // char *wordFrequency = (char*)malloc(10*sizeof(char));; 

    // int y;

    // for(y = 0; y < 10; y++)
    //     wordFrequency[y] = ' ';

    // sprintf(wordFrequency, "%d", count);

    // for(i = maxWordLength + 2; i < maxWordLength + 13; i++){
    //     line[i] = wordFrequency[counter];
    //     counter++;
    // }

    // line[maxWordLength + 13] = '\n';

    printf("%s\n", line);

    // Write content to "output.txt"
     write(fileNo, line ,200);
}