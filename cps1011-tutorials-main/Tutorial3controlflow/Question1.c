/* summing.c -- sums integers entered interactively */

#include <stdio.h>

int main(void)

{

    long num;

    long sum = 0L;      /* initialize sum to zero   */

    int status=1;


    printf("Please enter an integer to be summed ");

    printf("(q to quit): ");


    while (scanf("%ld",&num)==1)/* == means "is equal to"   */

    {
        printf("Please enter an integer to be summed ");

        printf("(q to quit): ");

        sum = sum + num;

    }

    printf("Those integers sum to %ld.\n", sum);



    return 0;

}
