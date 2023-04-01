/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#include <stdlib.h>
#include "sgets.h"
#define MAXTITL 40
#define MAXAUTL 40
 /* maximum number of books */
struct book { /* set up book template */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
int main(void)
{
    struct book *library; /* array of structures */
    int count = 0;
    int index, filecount;


    FILE * pbooks;
    int maxbks=sizeof(*pbooks);

    int size = sizeof (struct book);
    //allocate memory for array size
    //do *size since struct array
    library=(struct book *)malloc(maxbks*size);
    if(library==NULL){
        exit(EXIT_FAILURE);
    }


    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(pbooks); /* go to start of file */
    while (count < maxbks && fread(&library[count], size,
                                   1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n",library[count].title,
               library[count].author, library[count].value);
        count++;

    }
    filecount = count;
    if (count == maxbks)
    {
        maxbks+=1;
        library=(struct book *)realloc(library,maxbks*size);


    }
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < maxbks && sgets(library[count].title, MAXTITL) !=
                             NULL
           && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        sgets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);

        while (getchar() != '\n')
            continue; /* clear input line */
        if (count < maxbks)
            puts("Enter the next title.");
        if (count == maxbks)
        {
            puts("Enter the next title.");
            maxbks+=1;
            library=(struct book *)realloc(library,maxbks*size);
        }
    }
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",library[index].title,
                   library[index].author, library[index].value);
        fwrite(&library[filecount], size, count - filecount,
               pbooks);
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    free(library);//To relinquish memory
    return 0;
}