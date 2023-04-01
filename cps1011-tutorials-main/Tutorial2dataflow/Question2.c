#include <stdio.h>

int main(void)

{

    int integer;

    printf("Enter an integer to be turned into a character\n");

    scanf("%d",&integer);

    printf("the integer %d is %c in character form\n",integer,integer);
/*
 *Question 2 i)
 * if integer does not correspond to a character , then no character is printed
 *ii) done below
 */

    printf("the integer in octal is: %o and the integer in hexadecimal is: %hx",integer,integer);

    return 0;

}

