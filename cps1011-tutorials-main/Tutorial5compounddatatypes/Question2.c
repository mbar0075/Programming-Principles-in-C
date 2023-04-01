#include <stdio.h>


void copy(int arr1[], int arr2[] ,int size);

int main(void) {
    int size;
    printf("Enter how many numbers in the array\n");
    scanf("%d",&size);

    int arr1[size];//Declaring array
    int arr2[size];//Declaring copy array


    for(int i=0;i<size;i++) {//Populating array
        printf("Input elements %d",i+1);
        scanf("%d",&arr1[i]);
    }


    /*Question 2
     * array elements are all null
     * stack smashing detected
     */


    copy(arr1,arr2,300);//Calling function

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