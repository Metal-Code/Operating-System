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

    int queueIndex = 0;

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
            }
        }
        pageFaults++;
        if ((pageFaults <= frames) && (s == 0)) 
        {
            temp[m] = incomingStream[m];
        } 
        else if (s == 0) 
        {
            temp[queueIndex] = incomingStream[m];
            queueIndex = (queueIndex + 1) % frames;
        }
        printf("\n%d\t|", incomingStream[m]);
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1) 
            {
                printf(" %d |", temp[n]);
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
