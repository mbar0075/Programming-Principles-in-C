/* films2.c -- using a linked list of structures */
#include <stdio.h>
#include <stdlib.h>      /*has the malloc prototype*/
#include <string.h>      /*has the strcpy prototype*/
#include <ctype.h>
#include "sgets.h"

#define TSIZE 45      /*size of array to hold title*/

struct film {
    char title[TSIZE];
    int rating;
    struct film * next;  /* points to next struct in list */
};

void traverse(struct film *head);
void RemoveZero(struct film *head);
void Serialize(struct film *head);
struct film * DeSerialization();

int main(void){

    struct film * head = NULL;
    struct film * prev= NULL, * current = NULL;
    char input[TSIZE];

/*Gather  and store information*/
    traverse(DeSerialization());
    //traverse();

    puts("Enter first movie title:");

    while (sgets(input, TSIZE) != NULL && input[0] != '\0') {

        current = (struct film *) malloc(sizeof(struct film));

        if (head == NULL) {       /*first structure*/
            head = current;
        }
        else{                  /*subsequent structures*/
            prev->next = current;
        }

        current->next = NULL;
        strcpy(current->title, input);

        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);

        while(getchar() != '\n') {
            continue;
        }

        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }
    //traverse(head);
    //RemoveZero(head);
    Serialize(head);

/*Program done, so free allocated memory*/

    current = prev = head;

    while (current != NULL){
        current = current->next;
        free(prev);
        prev = current;
    }

    printf("Bye!\n");

    return 0;
}

void traverse(struct film *head){

    struct film*current;

    if (head == NULL) {
        printf("No data entered. ");
    }
    else {
        printf("Here is the movie list:\n");
    }
    current = head;

    while (current != NULL){
        printf("Movie: %s  Rating: %d\n",current->title, current->rating);
        current = current->next;
    }
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
        printf("Movie: %s Rating: %d",current->title, current->rating);
        current = current->next;
    }
}

void Serialize(struct film * head) {

    struct film*current;
    FILE *fp;

    current = head;
    fp = fopen("Serial.txt", "a");
    while (current != NULL) {
        //fwrite(current, sizeof(head), 1, fp);
        fprintf(fp,"%s,%d\n",current->title,current->rating);
        current = current->next;
    }
    fclose(fp);
}

struct film * DeSerialization(){
    struct film * head = NULL;
    struct film * current = NULL;
    struct film * prev = NULL;

    FILE *fp=fopen("Serial.txt", "r");
    rewind(fp);

    char tmp[50];
    //int lines = 0;

    while(fgets(tmp,50,fp)!=NULL) {

        current = (struct film *) malloc(sizeof(struct film));

        if (head == NULL){
            head = current;
        }
        else{
            prev->next = current;
        }

        char *pt;
        pt = strtok (tmp,",");
        while (pt != NULL) {
            if(isdigit(*pt)){
                current->rating=atoi(pt);
            }
            else{
                strcpy(current->title, pt);
            }
            pt = strtok (NULL, ",");
        }
        current->next = NULL;

        prev = current;
    }

    return head;
}
