/* films1.c -- using an array of structures */
#include <stdio.h>
#include <stdlib.h>
#include "sgets.h"
#define TSIZE 45 /* size of array to hold title */
#define FMAX 5 /* maximum number of film titles */
struct film {
    char *title;//Dynamic array and change the declaration
    int rating;
};
int main(void)
{
    struct film *movies=(struct film *)malloc(sizeof(struct film)*FMAX);
    int i = 0;
    int j;
    for(int x=0;x<FMAX;x++){
        //To allocate memory to all the titles in the movies array
        movies[x].title=(char *)malloc( sizeof(char)*255);
    }
    puts("Enter first movie title:");
    while (i < FMAX && sgets(movies[i].title, TSIZE) != NULL &&
           movies[i].title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &movies[i++].rating);
        while(getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
    }
    if (i == 0)
        printf("No data entered. ");
    else
        printf ("Here is the movie list:\n");
    for (j = 0; j < i; j++)
        printf("Movie: %s Rating: %d\n", movies[j].title,
               movies[j].rating);
    printf("Bye!\n");
    return 0;
}