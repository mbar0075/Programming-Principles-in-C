// names3.c -- use pointers and malloc()
#include <stdio.h>
#include <string.h> // for strcpy(), strlen()
#include <stdlib.h> // for malloc(), free()
#include "sgets.h"
#define SLEN 81
struct namect {
    char * fname; // using pointers
    char * lname;
    int letters;
};
void getinfo(struct namect *); // allocates memory
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); // free memory when done
int main(void)
{
    int maxppl=5;
    int size=sizeof(struct namect);
    struct namect person;
    struct namect *array;
    array=(struct namect*)malloc(maxppl*size);

    for(int i=0;i<maxppl;i++) {
        getinfo(&person);
        makeinfo(&person);
        showinfo(&person);
        array[i]=person;
        if(i==(maxppl-1)){
            printf("Do you want to enter another person, if not enter q");
            char input=getchar();
            while(getchar()!='\n');
            if(input!='q') {
                maxppl += 1;
                array = (struct namect *) realloc(array, maxppl * size);
            }
        }
    }
    for(int i=0;i<maxppl;i++) {
        person=array[i];
        showinfo(&person);
    }
    cleanup(&person);

    return 0;
}
void getinfo (struct namect * pst)
{
    char temp[SLEN];
    printf("Please enter your first name.\n");
    sgets(temp, SLEN);
    // allocate memory to hold name
    pst->fname = (char *) malloc(strlen(temp) + 1);
    // copy name to allocated memory
    strcpy(pst->fname, temp);
    printf("Please enter your last name.\n");
    sgets(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}
void makeinfo (struct namect * pst)
{
    pst->letters = strlen(pst->fname) +strlen(pst->lname);
}
void showinfo (const struct namect * pst)
{
    printf("%s %s, your name contains %d letters.\n",pst->fname, pst->lname, pst->letters);
}
void cleanup(struct namect * pst)
{
    free(pst->fname);
    free(pst->lname);
}