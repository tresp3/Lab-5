#include "Problem2methods.h"
#include <stdio.h>

int main(int argc, char*argv[])
{
    int score = 2;
    while(score!=0 && score!=1)
    {
        printf("Enter 0 or 1 to STOP: \n Enter the NFL score: ");
        scanf("%d", &score);
        printf("\n");
        if(score!=0)
        {
            printPossibleScores(score);
        }
        printf("\n");
    }
    
    
}
