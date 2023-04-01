// sum_arr1.c -- sums the elements of an array
// use %u or %lu if %zd doesn't work
#include <stdio.h>
#define SIZE 10

int sum(int *start,int *end, int arr[]);

int main(void)
{
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;
    answer = sum(marbles , marbles + SIZE,marbles);// do 10 since it points at null value
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %llu bytes.\n",sizeof (marbles));

    return 0;
}

int sum(int *start,int *end,int arr[]) // how big an array?
{
    int total = 0;
    printf("The size of ar is %u bytes.\n", sizeof(arr));
    do
    {
        total += *start;
        start++;
    }while (start<end);

    return total;
}