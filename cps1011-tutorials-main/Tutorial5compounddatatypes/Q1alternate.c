#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void copy(double num[],double copy[],int size);

int main(void) {
    double num[100];
    double value;
    char x;
    int counter = 0;

    printf("Please input a string of numbers delimited by white spaces");
    fflush(stdout);
    do{
        char str1[100]="";
        do {
            x = getchar();
            if(!isalpha(x)) {
                strncat(str1, &x, 1);
                value = atof(str1); //atoi converts String to int || atof converts String to float
            }
        } while (!isspace(x));
        num[counter] = value;
        counter++;

    }while(x!='\n');


    double tmp[100];

    copy(num,tmp,counter);

    for(int i=0;i<counter;i++){
        printf("%.2f\n",tmp[i]);
    }

    return 0;
}

void copy(double num[],double copy[],int size){
    for(int i=0;i<size;i++){
        copy[i]=num[i];
    }
}