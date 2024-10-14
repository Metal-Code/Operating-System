#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void) 
{
    pid_t pid;
    if((pid = fork()) < 0)
        printf("fork error\n");
    else if(pid == 0)
        printf("child process id is %d\n", getpid());
    else 
    {
        sleep(10);
        printf("*******parent\n");
        system("ps -ax | tail");
    }
    
    exit(0);
}
