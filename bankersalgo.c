#include <stdio.h>  
int main()  
{  
    int i, j, k;  
    int max[5][3];
    int need[5][3];    
    int alloc[5][3];
    int avail[3];
    char resource[] = {'A','B','C'};
	
    for(i = 0; i<5;i++)
    {
        printf("Enter The Maximum Need Of Resources of Process P%d : \n",i);
        for (j = 0; j<3; j++)
        {
            printf("Enter Max Resource %c : \n",resource[j]);
            scanf("%d",&max[i][j]);
        }
    }
    printf("\n");
    for(i = 0; i<5;i++)
    {
        printf("Enter The Allocated Resources of Process P%d : \n",i);
        for (j = 0; j<3; j++)
        {
            printf("Enter Allocated Resource %c : \n",resource[j]);
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\n\n");
    for(j = 0; j<3; j++)
    {
        printf("\nEnter The Available Resource %c : \n",resource[j]);
        scanf("%d",&avail[j]);
    }
    printf("\n\n\n");

    int f[5], ans[5], ind = 0;  
    for (k = 0; k < 5; k++)  
    {  
        f[k] = 0;  
    }  
    
    for (i = 0; i < 5; i++)  
    {  
        for (j = 0; j < 3; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  

    printf("The Data Given is : \n");
    printf("Process  |  Max    Allocated    Need\n");
    printf("Numbers  | A B C     A B C     A B C\n");
    printf("--------------------------------------------\n");
    
    for(i = 0; i <5; i++)
    {
        printf("P%d       | %d %d %d     %d %d %d     %d %d %d\n",i,
        max[i][0],max[i][1],max[i][2],alloc[i][0],alloc[i][1],alloc[i][2],need[i][0],need[i][1],need[i][2]);   
    }

    printf("\nAvailable Resources Are : A-%d B-%d C-%d\n\n",avail[0],avail[1],avail[2]);   
    int y = 0;  
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < 5; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < 3; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < 3; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }  

    int flag = 1;  
    for (i = 0; i < 5; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe");  
            break;  
        }  
    }  
    
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < 5 - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d", ans[5 - 1]);  
    }  
    return (0);  
}  

