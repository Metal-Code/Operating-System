#include <stdio.h>

int main() 
{
    int pageFaults = 0;
    int frames;
    int pages;
    char ch;
    int i, m, n;

    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &pages);

    int incomingStream[pages];

    printf("Enter the reference string: ");
    for (i = 0; i < pages; i++) 
    {
        scanf("%d", &incomingStream[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("\n\nPaging Will Be Done As Follows:\n");
    int temp[frames];

    for (m = 0; m < frames; m++) 
    {
        temp[m] = -1;
    }

    int pos[frames];
    int minpos;
    int final[frames];
   
    for (m = 0; m < pages; m++) 
    {
        int s = 0;
        ch = 'M';
       
        for (n = 0; n < frames; n++) 
        {
            if (incomingStream[m] == temp[n]) 
            {
                s++;
                pageFaults--;
                ch = 'H';
                break;
            }
        }

        pageFaults++;
        if (s == 0) 
        {
            if (pageFaults <= frames) 
            {
                temp[m] = incomingStream[m];
            } 
            else 
            {
                minpos = m;
                for (i = 0; i < frames; i++) 
                {
                    pos[i] = -1;
                    for (int j = m - 1; j >= 0; j--) 
                    {
                        if (incomingStream[j] == temp[i]) 
                        {
                            pos[i] = j;
                            break;
                        }
                    }
                    if (pos[i] == -1) 
                    {
                        minpos = pos[i];
                        break;
                    }
                }

                for (i = 0; i < frames; i++) 
                {
                    if (pos[i] <= minpos) 
                    {
                        minpos = pos[i];
                        n = i;
                    }
                }
                temp[n] = incomingStream[m];
            }
        }

        for(i = 0; i< frames; i++) 
        {
            final[i] = temp[frames-i-1];
        }

        printf("\n%d\t|", incomingStream[m]);
        for (n = frames-1; n >= 0; n--) 
        {
            if (final[n] != -1) 
            {
                printf(" %d |", final[n]);
            } 
            else 
            {
                printf(" - |");
            }
        }
        printf(" %c", ch);
    }

    printf("\n\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
