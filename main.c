//
//  Name this file: stats.c
//  StatisticsLab
//
//  Student Name: Melanie Summers;
//  Student id: 012090935;
//  Name of the assignment: Statistics Lab;
//  Date: 10/28/18;
//  Name and version of the C Compiler: Xcode v. 9.4.1;
//  Name of Operating System: Mac OS High Sierra v. 10.13.6;
//


#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

int compare(const void *p, const void *q);

int main(void) {
    int i, j;
    int scoresArray[] = { 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95, 80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65 };
    
    //before sort print statements
    printf( "\n Un-Sorted Test Scores: \n");
    j = 1;
    for(i = 0; i < SIZE; i++){
        if ( j % 5 ==0){
            printf( "\n");
        } else {
                printf("%d ", scoresArray[i]);
        }
        j++;
    }
    
    //after sort print statements
    qsort(scoresArray, SIZE, sizeof(int), compare);
    printf( "\n Sorted Test Scores: \n");
    j = 1;
    for(i = 0; i < SIZE; i++){
        if ( j % 5 ==0){
            printf( "\n");
        } else {
            printf("%d ", scoresArray[i]);
        }
        j++;
    }
    
    //print out the unsorted test scores, five per line
    
    //sort array in ascending order
    
    //print out the sorted test scores, five per line
    
    return 0;
}

int compare (const void *p, const void *q) {
    if (*(int *)p < *(int *)q) {
        return -1;
    }
        return *(int *)p > *(int *)q;
}


