/* names2.c -- passes and returns structures */
#include <stdio.h>
#include <string.h>
#include "sgets.h"
#define NLEN 30

//Declaring datatype string_t as array of characters
typedef char string_t[NLEN];

typedef struct {
    string_t fname;
    string_t lname;
    int letters;
}name_t;//name_t is name for structure

 name_t getinfo(void);
 name_t makeinfo( name_t);
void showinfo( name_t);

int main(void)
{
    name_t person;
    person = getinfo();
    person = makeinfo(person);
    showinfo(person);
    return 0;
}
name_t getinfo(void)
{
    name_t temp;
    printf("Please enter your first name.\n");
    sgets(temp.fname, NLEN);
    printf("Please enter your last name.\n");
    sgets(temp.lname, NLEN);
    return temp;
}
name_t makeinfo(name_t info)
{
    info.letters = strlen(info.fname) + strlen(info.lname);
    return info;
}
void showinfo(name_t info)
{
    printf("%s %s, your name contains %d letters.\n",
           info.fname, info.lname, info.letters);
}