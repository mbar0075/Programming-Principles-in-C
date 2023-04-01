#include <stdio.h>


void copy(int arr1[], int arr2[] ,int size);

int main(void) {
    //1)Write a function that makes a copy of an array of integers.
    //Write a test driver for it.

    int size;
    printf("Enter how many numbers in the array\n");
    scanf("%d",&size);

    int arr1[size];//Declaring array
    int arr2[size];//Declaring copy array

    /*Another way of Declaration
     * int a[17];
     * size_t n = sizeof(a)/sizeof(a[0]);
     */

    for(int i=0;i<size;i++) {//Populating array
        printf("Input elements %d",i+1);
        scanf("%d",&arr1[i]);
    }

    copy(arr1,arr2,size);//Calling function

    printf("Printing array 1\n");
    for(int i=0;i<size;i++) {
        printf(" %d", arr1[i]);
    }
    printf("\nPrinting array 2\n");
    for(int i=0;i<size;i++) {
        printf(" %d", arr2[i]);
    }
    return 0;
}

void copy(int arr1[],int arr2[], int size){
    for(int i=0;i<size;i++) {
        arr2[i]=arr1[i];
    }
}