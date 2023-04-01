/* films2.c -- using a linked list of structures */
#include <stdio.h>
#include <stdlib.h> /* has the malloc prototype */
#include <string.h> /* has the strcpy prototype */
#include "sgets.h"
#define TSIZE 45 /* size of array to hold title */
struct film {
    char title[TSIZE];
    int rating;
    struct film * next; /* points to next struct in list */
};
void RemoveZero(struct film * head);

int main(void)
{
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];
/* Gather and store information */
    puts("Enter first movie title:");
    while (sgets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL) /* first structure */
            head = current;
        else /* subsequent structures */
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while(getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    RemoveZero(head);

/* Show list of movies */
 /*   if (head == NULL)
        printf("No data entered. ");
    else
        printf ("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n",
               current->title, current->rating);
        current = current->next;
    }*/
/* Program done, so free allocated memory */
    current = prev = head;
    while (current != NULL)
    {
        current = current->next;
        free(prev);
        prev = current;
    }
    printf("Bye!\n");
    return 0;
}

void RemoveZero(struct film * head){
    struct film*current;
    if (head == NULL)
        printf("No data entered. ");
    else{
        printf ("Removing files with rating of 0\n");

    }

    current = head;
    while (current != NULL)
    {
        if(current->rating==0){
            current =  current->next;
        }
        printf("Movie: %s Rating: %d\n",
               current->title, current->rating);
        current = current->next;
    }
}