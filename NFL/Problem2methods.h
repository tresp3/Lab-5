#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>

void printPossibleScores(int score)
{
    int points[] = {8,7,6,3,2};
    int maxes[5];
    for (int i =0; i<5; i++)
    {
        maxes[i] = score/points[i];
    }
    for(int a = 0; a<=maxes[0]; a++)
    {
        for(int b = 0; b<=maxes[1]; b++)
        {
            for(int c = 0; c<=maxes[2]; c++)
            {
                for(int d = 0; d<=maxes[3]; d++)
                {
                    for(int e = 0; e<=maxes[4]; e++)
                    {
                        if((a*points[0]) + (b*points[1]) + (c*points[2]) + (d*points[3]) + (e*points[4]) == score)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n",a,b,c,d,e);                            
                        }
                    }
                }
            }
        }
    }
}

#endif