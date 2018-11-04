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

FILE *fp;

int main(void);
int compare(const void *p, const void *q);
void outputUnsorted(int scoresArray[]);
void scoresSort(int scoresArray[], int max);
void frequencyChart(int scoresArray[], int frequency[], int max);
void passingFailing (int scoresArray[], int max);
void printMean(int scoresArray[], int max);
void printMode(int scoresArray[], int frequency[]);
void printMedian(int scoresArray[], int max);

int main(void) {
    int frequency[101];

    int scoresArray[] = { 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95, 80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65 };
    
    fp = fopen("csis.txt", "w");
    
    outputUnsorted(scoresArray);
    scoresSort(scoresArray, SIZE);
    frequencyChart(scoresArray, frequency, SIZE);
    passingFailing(scoresArray, SIZE);
    printMean(scoresArray, SIZE);
    printMode(scoresArray, frequency);
    printMedian(scoresArray, SIZE);
    
    fclose(fp);
    return 0;
}

//function that outputs test scores (unsorted, five per line)
void outputUnsorted (int scoresArray[]){
    int i, j;
    printf(     "\nUn-Sorted Test Scores: \n");
    fprintf(fp, "\nUn-Sorted Test Scores: \n");
    j = 0;
    for(i = 0; i < SIZE; i++){
        if ( j % 5 == 0) printf( "\n");
        printf(     "%d ", scoresArray[i]);
        fprintf(fp, "%d ", scoresArray[i]);
        j++;
    }
}

//function to sort the test scores:
void scoresSort(int scoresArray[], int max){
    int i, j, temp;
    printf(     "\nSorted Test Scores: \n");
    fprintf(fp, "\nSorted Test Scores: \n");
    
    for (i = 1; i < max; i++){
        temp = scoresArray[i];
        j = i - 1;
        while(j >= 0 && temp < scoresArray[j]) {
            scoresArray[j + 1] = scoresArray[j];
            j = j - 1;
        }
        scoresArray[j+1] = temp;
    }
    j = 0;
    for(i = 0; i < SIZE; i++){
        if ( j % 5 == 0) printf( "\n");
        printf(     "%d ", scoresArray[i]);
        fprintf(fp, "%d ", scoresArray[i]);
        j++;
    }
}

//calculate and print out the frequency distribution chart
void frequencyChart(int scoresArray[], int frequency[], int max){
    printf(     "\n %5s %10s \n", "Score", "Frequency");
    fprintf(fp, "\n %5s %10s \n", "Score", "Frequency");
    printf(     "%5s %10s \n", "-----", "---------");
    fprintf(fp, "%5s %10s \n", "-----", "---------");
    
    for(int i = 0; i < 101; i++){
        frequency[i] = 0;
       
    }
    for(int i = max -1; i > 0; i--){
        frequency[scoresArray[i]]++;
    }
    
    for(int i = 100; i > 0; i--){
     if(frequency[i]){
        printf(     "%5d %10d\n", i, frequency[i]);
        fprintf(fp, "%5d %10d\n", i, frequency[i]);
        }
    }
}

//output the percentage of passing and failing test scores to the nearest tenth.
void passingFailing (int scoresArray[], int max){
    int pass = 0;
    int fail = 0;
    for(int i = 0; i < max; i++){
        if(scoresArray[i] > 60){
            pass++;
        } else {
            fail++;
        }
    }
    printf(     "The percentage of passing scores: %.1lf\n", (double)pass/max * 100);
    fprintf(fp, "The percentage of passing scores: %.1lf\n", (double)pass/max * 100);
    printf(     "The percentage of failing scores: %.1lf\n", (double)fail/ max * 100);
    fprintf(fp, "The percentage of failing scores: %.1lf\n", (double)fail/ max * 100);
}

//calculate and print out the mean of the test scores to the nearest tenth
void printMean(int scoresArray[], int max){
    double sum = 0;
    double mean = 0;
    for(int i = 0; i < max; i++){
        sum += scoresArray[i];
        mean = sum/ max;
    }
    printf(     "The sum = %3.1lf and mean = %.1lf of the test scores. \n", sum, mean);
    fprintf(fp, "The sum = %3.1lf and mean = %.1lf of the test scores. \n", sum, mean);
}

//print out the mode of the test scores to nearest tenth
void printMode(int scoresArray[], int frequency[]){
    int mode = 0;
    for(int i = 0; i < 101; i++){
        if(frequency[i] > frequency[mode]){
            mode = i;
        }
    }
    printf(     "The mode is: %d \n", mode);
    fprintf(fp, "The mode is: %d \n", mode);
}

// print out the median:
void printMedian(int scoresArray[], int max){
    double median = 0;
    if(max % 2 == 0){
        median = scoresArray[max/2];
        median += scoresArray[max/2 - 1];
        median /=2;
        
    } else {
        median = scoresArray[max/2] ;
    }
    printf(     "The median is: %.1lf\n", median);
    fprintf(fp, "The median is: %.1lf\n", median);
}




