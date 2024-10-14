#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void swap(int* xp, int* yp) 
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() 
{
    bool swapped;
    pid_t num_pid;
    int a[5], i, j;
    int min_idx;
    
    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++) 
    {
        scanf("%d", &a[i]);
    }
    
    num_pid = fork();
    if(num_pid < 0) 
    {
        printf("Error in fork execution\n");
    }
    else if(num_pid == 0) 
    {
        printf("Child: Its ID is %d\n", getpid());
        for(i = 0; i < 5 - 1; i++) 
        {
            min_idx = i;
            for(j = i + 1; j < 5; j++) 
            {
                if(a[j] < a[min_idx]) 
                {
                    min_idx = j;
                }
            }
            swap(&a[min_idx], &a[i]);
        }
        printf("Descending order\n");
        for(i = 0; i < 5; i++) 
        {
            printf("%d\n", a[i]);
        }
        exit(0);
    }
    else {
        printf("Parent: Its ID is %d\n", getpid());
        for(i = 0; i < 5 - 1; i++) 
        {
            min_idx = i;
            for(j = i + 1; j < 5; j++) 
            {
                if(a[j] > a[min_idx]) 
                {
                    min_idx = j;
                }
            }
            swap(&a[min_idx], &a[i]);
        }
        wait(NULL);
        printf("Ascending order\n");
        for(i = 0; i < 5; i++) 
        {
            printf("%d\n", a[i]);
        }
    }
    
    exit(0);
}
