#include "Problem1methods.h"
#include <stdio.h>

int main(int argc, char*argv[])
{
    double sales[12];
    char* months[] = {"January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    read_sales_file(sales);
    printSales(months, sales);
    printSummary(months,sales);
    printSixMonthAverage(months, sales);
    sortPrint(months,sales);
    return 0;
}