#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Node.h"
#include "HashTable.h"

// TODO
// Max file size
#define MAXSIZE 50000

// Represents hash table array (length : 26)
HashNode** hashTable = NULL;

// Converts given text into words
void wordConverter(char*);

// Converts given word to lowercase
char* toLowerCase(char*);

// Finds according hashTable's index for the given word
void hashTableWordPlacer(const char*);

// Prints all data for each hashtable's index
void printAllData();

int main(int argc, char  *argv[])
{
    // Initialize hash table
    hashTable = createHashTable();

    char *buf = (char*)malloc(MAXSIZE*(sizeof(char)));

    int fdin, i;

    // Sends each row to wordConverter
    wordConverter(buf);

    // Handle many files open and read processes
    for(i = 1; i < argc; i++){

        fdin = open(argv[i],O_RDONLY);

        while(read(fdin, buf, MAXSIZE) > 0)
        {
            // Sends each row to wordConverter
            wordConverter(buf);
        }

        close(fdin);
    }

    char* text = (char*)malloc(MAXSIZE*(sizeof(char)));

    printf("If you won't use standart input. Control+D for determinate the program! \n");

    while(fgets(text, MAXSIZE, stdin) != NULL){

        // Sends each row to wordConverter
        wordConverter(text);

        // gets text from user
        fgets(text, MAXSIZE, stdin);

        // Sends each row to wordConverter
        wordConverter(text);
    }

    // Prints current status
    printAllData();

    return 0;
}

void wordConverter(char* line){

    // counter
    int i;
    // Replace space for each character that' not a alphacharacter
    for(i = 0; i < strlen(line); i++){
        if(isalpha(line[i]) == 0){
            line[i] = ' ';
        }
    }

    // To lowercase
    line = toLowerCase(line);

    // Represents a seperated word
    const char *word;

    word = strtok(line, " ");

    while (word != NULL)  {

      // Sends "word" to the function for placing it to the according index 
      hashTableWordPlacer(strdup(word));

      word = strtok (NULL, " ");

      if(word == NULL) continue;
    }
}

char* toLowerCase(char* text) {
    // Represents a lowercase word
    char *word = (char*)malloc(strlen(text) * sizeof(char));

    int i;

    for(i = 0; i < strlen(text); i++){

        char ch = tolower(text[i]);

        word[i] = ch;
    }

    return word;
}

void hashTableWordPlacer(const char* word){
    int i;
    for(i = 0; i < 26; i++){
        if(hashTable[i]->letter == word[0]){
            // Sends "word" and bst's root to method
            hashTable[i]->root = addNodeToBST(hashTable[i]->root, word);
        }
    }
}

void printAllData(){
    int i;
    for(i = 0; i < 26; i++){
        // prints bst's current status
        printBST(hashTable[i]->root);
    }

    printf("\n");
}