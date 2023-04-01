
#include <stdio.h>
#include "ObjectClass.h"

void fibonacci(int n);

int Rfibonacci(int n);


void Question2(void)

{

    int num,i=0;



    printf("This program calculates fibonacci.\n");
    printf("Enter a value  (q to quit):\n");
    while (scanf("%d", &num) == 1)

    {

        printf("\nFibonacci series with loops\n");
            fibonacci(num);

        printf("\nFibonacci series with recursion\n");
            for (int  c = 1 ; c <= num ; c++ ){
            printf("%d ,", Rfibonacci(i));
            i++;
        }


        printf("\nEnter a value in the range 0-12 (q to quit):\n");
    }

    printf("Bye.\n");

    clear();

}


 int Rfibonacci(int n)   // fibonacci sequence using recursion
{
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
        return 1;
    else
        return ( Rfibonacci(n-1) + Rfibonacci(n-2) );
}


void fibonacci(int n)     // fibonacci sequence using iteration
{
    int sum,num1=0,num2=1,count=n,i=0;
    while(i<count) {
        printf("%d ,", num1);
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
        i++;
    }

}


