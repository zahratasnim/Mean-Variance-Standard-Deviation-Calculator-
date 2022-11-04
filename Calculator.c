#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include <math.h>
#define BSIZE 1024


int main(){

    const int size =1000;
    int count=0;
    FILE *fp;
    char row[size];
    int num[size];
    double mean;
    int i;
    float v;
    float variance;
    float sd;
   

    fp = fopen("sensor.csv","r"); //opening and reading csv file

    int sum= 0;
    i=0;
    while (feof(fp) != true)        //calculating sum and count
    {   
        fgets(row, size, fp);
        sum = sum + atoi(row);
        count= count +1;
        num[i] = atoi(row);
        i++;
    }

      
    count=count-1;
    sum= sum-1; 
    mean = (double) sum/count;

    v=0;                        //calculating variance and standard deviation
    for (i = 0; i < count; i++) 
    {
        v = v + pow((num[i] - mean), 2);
    }
    variance = v/count; 
    sd = sqrt(variance);
    
    printf("Count: %d\n", count);
    printf("Sum: %d\n", sum);
    printf("Mean: %f\n", (double)mean);
    printf("Variance: %f\n", variance);
    printf("Standard deviation: %f\n", sd);
    
    return 0;
}

