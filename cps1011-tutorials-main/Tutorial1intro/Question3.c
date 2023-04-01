/* two_func.c -- a program using two functions in one file */
#include <stdio.h>

void butler(char name[30]);      /* ISO/ANSI C function prototyping */

int main(void)

{
    char name[30];
    printf("Enter name\n");
    scanf("%s",name);

    printf("I will summon the butler function.\n");
    butler(name);
    printf("Yes. Bring me some tea and writeable CD-ROMS.\n");

    return 0;

}

void butler(char name[30])          /* start of function definition */
{
    printf("You rang, Sir %s ?\n",name);
}
