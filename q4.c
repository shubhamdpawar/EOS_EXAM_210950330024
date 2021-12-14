#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    int fdr, fdw;
    fdr = open("dictionary.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    fdw = open("dictionary.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if (-1 == fdr)
    {
        perror("Error:\n");
        exit(EXIT_FAILURE);
    }

    if (-1 == fdw)
    {
        perror("Error:\n");
        exit(EXIT_FAILURE);
    }

    read(fdr,"dictionary.txt",1024);
    write(fdw,"dictionary.txt",1024);

    printf("Contents:%s",fdw);
   
    close(fdr);
    close(fdw);

    return 0;
}
