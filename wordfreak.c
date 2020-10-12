#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char  *argv[])
{
    if(argc == 0) { // Standart input
        // TODO
    }
    else if(argc > 1){ // Handle given txt files

        int fdin;

        char buf[1024];

        fdin = open(argv[1],O_RDONLY);

        while(read(fdin, buf, 1024) > 0)
        {
            printf("%s\n", buf);
        }

        close(fdin);

}
  return 0;
}