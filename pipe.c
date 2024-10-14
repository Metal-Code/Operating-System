#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#define max 50

int main()
{
  int fd[2], n;
  pid_t x;
  char str1[max], str2[max];
  n = pipe(fd);

  x = fork();
  if (x == 0)
  {
    read(fd[0], str2, max);
    printf("child id = %d\n", getpid());
    printf("The Child Process: %s", str2);
  }
  else
  {
    printf("parent id = %d\n", getpid());
    close(fd[0]);
    printf("enter your message:\n");
    scanf("%s", str1);
    printf("Writing msg to pipe\n");
    write(fd[1], str1, max);
    close(fd[1]);
  }
  return 0;
}
