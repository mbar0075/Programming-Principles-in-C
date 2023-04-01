// fathom_ft.c -- converts 2 fathoms to feet

#include <stdio.h>

int main(void)

{
//Declaration using lvalue (locator value) container fathoms
    int feet, fathoms;


//Declaration using rvalue  6*fathoms , fathoms=2
    fathoms = 2;

    feet = 6 * fathoms;

    printf("There are %d feet in %d fathoms!\n", feet, fathoms);

    printf("Yes, I said %d feet!\n", 6 * fathoms);



    return 0;

}
