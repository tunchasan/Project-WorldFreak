#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Converts given text into words
void wordConverter(char*);

// Converts given word to lowercase
char* toLowerCase(char*);

int main(int argc, char  *argv[])
{
    if(argc == 0) { // Standart input
        // TODO
    }
    else if(argc > 1){ // Handle given txt files

        int fdin;

        char *buf = (char*)malloc(1024*(sizeof(char)));

        fdin = open(argv[1],O_RDONLY);

        while(read(fdin, buf, 1024) > 0)
        {
            // Sends each row to wordConverter
            wordConverter(buf);
        }

        close(fdin);
    }

  return 0;
}

void wordConverter(char* line){
    // counter
    int i;
    // Replace space for each character that' not a alphacharacter
    for(i = 0; i < strlen(line); i++){
        if(!isalpha(line[i])){
            line[i] = ' ';
        }
    }

    // To lowercase
    toLowerCase(line);

    // Represents a seperated word
    const char *word;

    word = strtok(line, " ");

    while (word != NULL)  {
      printf ("%s\n", word);
      word = strtok (NULL, " &");
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