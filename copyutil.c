#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char buffer[2048];
void copy(int old, int new) 
{
    int count;
    count = read(old, buffer, sizeof(buffer));
    write(new, buffer, count);
}

void main(int argc, char *argv[]) 
{
    int fold, fnew;
    if (argc != 3) 
    {
        printf("Need 2 arguments to copy program.\n");
        exit(1);
    }
    fold = open(argv[1], O_RDONLY);
    if (fold == -1) 
    {
        printf("Cannot Open the file %s.\n", argv[1]);
        exit(1);
    }
    fnew = creat(argv[2], 0666);
    if (fnew == -1) 
    {
        printf("Cannot Create File %s \n", argv[2]);
        exit(1);
    }
    copy(fold, fnew);
    printf("File Copied Successfully.\n");
    close(fold);
    close(fnew);
    exit(0);
}
