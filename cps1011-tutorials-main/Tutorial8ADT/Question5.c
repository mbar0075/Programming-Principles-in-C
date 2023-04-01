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
        printf("Movie: %s Rating: %d\n",current->title, current->rating);
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
        fprintf(fp,"%s %d\n",current->title,current->rating);
        current = current->next;
    }
    fclose(fp);
}

struct film * DeSerialization(){
    struct film Array[30];
    struct film * head = NULL;
    struct film * current = NULL;
    struct film * prev = NULL;

    FILE *fp=fopen("Serial.txt", "r");
    char tmp[50];
    rewind(fp);

    int lines=0;

    while(fgets(tmp,50,fp)!=NULL) {//Counting the no lines
        lines++;
    }

    rewind(fp);

    for(int x=0;x<lines;x++){
        char tmp[50];
        struct film tmp2;

        fscanf(fp,"%s",tmp);
        strcpy(tmp2.title,tmp);
        strcpy(Array[x].title,tmp2.title);

        fscanf(fp,"%s",tmp);
        tmp2.rating=atoi(tmp);
        Array[x].rating=tmp2.rating;
    }

    for(int x=0;x<lines;x++){

        current = (struct film *) malloc(sizeof(struct film));

        if (head == NULL){       /*first structure*/
            head = current;
            //printf("\n%s-%d-%p\n",head->title,head->rating,head->next);
        }
        else{                  /*subsequent structures*/
            prev->next = current;
            //printf("\n%s-%d-%p\n",prev->title,prev->rating,prev->next);
        }

        current->next = NULL;
        strcpy(current->title,Array[x].title);
        current->rating=Array[x].rating;

        /*while(getchar() != '\n') {
            continue;
        }*/

        prev = current;
    }
    for(int c=0;c<lines;c++) {
        printf("%s-%d-%p->\n",head->title,head->rating, head->next);
        head=head->next;
    }

    return head;
}