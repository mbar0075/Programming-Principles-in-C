
#include <stdio.h>
#include "ObjectClass.h"

int gcd(int x,int y);

int lgcd(int x,int y);

void Question3(void)

{

    int x,y;


    do {
        printf("Greatest common divider Enter x and y , where x>y\n");
        printf("Enter x\n");
        scanf("%d", &x);
        printf("Enter y\n");
        scanf("%d", &y);
    }while(x<y);

            printf("\nThe Greatest common difference using recursion is: %d", gcd(x,y));

            printf("\nThe Greatest common difference using loops is: %d", lgcd(x,y));


    printf("\nBye.\n");



}


int gcd(int x,int y)   // Using recursion
{
    if ( y == 0 )
        return x;
    else
        return gcd(y,(x%y));
}

int lgcd(int x,int y)   // Using loops
{
    int result;
    do {
        if (y == 0)
            result= x;
        else if (y > 0) {
            x = y;
            result=y;
            y = x % y;
        }
    } while (y != 0);

    return result;
}


