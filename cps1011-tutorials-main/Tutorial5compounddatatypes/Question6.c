/* fgets1.c -- using fgets() and fputs() */
#include <stdio.h>
#include "sgets.h"
#define STLEN 14

int main(void)
{
    char words[STLEN];
    puts("Enter a string, please.");
    sgets(words, STLEN);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("\nEnter another string, please.");
    sgets(words, STLEN);
    printf("\nYour string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("\nDone.");

    return 0;
}