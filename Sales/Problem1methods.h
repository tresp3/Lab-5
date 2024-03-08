#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>

void read_sales_file(double* sales)
{
    FILE *fp = fopen("sales.txt", "r");
    for(int i = 0; i<12; i++)
    {
        fscanf(fp, "%lf", &sales[i]);
    }
        
    fclose(fp);


}

void printSales(char* months[],double* sales)
{
    printf("Monthly sales report for 2022: \n");
    printf("Month \t  \t Sales \n");
    for(int i = 0; i<12; i++)
    {
        printf("%-9s \t %.2lf \n", months[i], sales[i]);
    }
    printf("\n");
}

void swap(char* months[],double* sales, int a, int b)
{
    double temps = sales[a];
    char* tempm[] = {months[a]};
    sales[a] = sales[b];
    months[a] = months[b];
    sales[b] = temps;
    months[b] = tempm[0];
}

void printSixMonthAverage(char* months[],double* sales)
{
    printf("Six-Month Moving Average Report: \n");
    int averages =  7;
    for (int i = 0; i<averages; i++)
    {
        double sum = 0;
        for(int j = i; j<=averages + i - 2; j++)
        {
            sum+=sales[j];
        }
        double average = sum/6;
        printf("%-9s - %s  $%.2lf \n", months[i], months[averages + i - 2], average);
    }
    printf("\n");
}

int findMax(double* sales)
{
    int index = 0;
    for(int i = 1; i<12; i++)
    {
            if(sales[i]>sales[index])
            {
                index = i;
            }
    }
    return index;
}

int findMin(double* sales)
{
    int index = 0;
    for(int i = 1; i<12; i++)
    {
            if(sales[i]<sales[index])
            {
                index = i;
            }
    }
    return index;
}

void printSummary(char* months[], double* sales)
{
    printf("Sales summary: \n");
    int minIndex = findMin(sales);
    int maxIndex = findMax(sales);
    printf("Minimum sales: \t \t $%.2lf \t (%s) \n ", sales[minIndex], months[minIndex]);
    printf("Maximum sales: \t $%.2lf \t (%s) \n ", sales[maxIndex], months[maxIndex]);
    double sum = 0;
    for(int i = 0; i<12; i++)
    {
        sum+=sales[i];
    }
    double average = sum/12;
    printf("Average sales: \t $%.2lf \n ", average);
    printf("\n");
}

void sortPrint(char* months[], double* sales)
{
    for(int i = 0; i<12; i++)
    {
        for(int j =0; j<12; j++)
        {
            if(sales[i]>sales[j])
            {
                swap(months,sales,i,j);
            }
        }
    }
    printf("Sales Report (Highest to Lowest): \n");
    printf("Month \t \t Sales \n");
    for(int i = 0; i<12; i++)
    {
        printf("%-9s \t %.2lf \n", months[i], sales[i]);
    }
    printf("\n");
}

#endif
