#include <stdio.h>

int main(void)

{

    int n,factorial=1;

    printf("Factorial \nEnter an integer\n");

    scanf("%d",&n);
    for (int i = 1; i <=n ; i++) {
        factorial*=i;
    }
    printf("The factorial is: %d\n",factorial);

    return 0;

}

