
#include <stdio.h>
#include <string.h>
#include "ObjectClass.h"


void Function(char *x);


void Question5(void)

{


    char input[100];
    printf("Enter String\n");
    scanf("\n%[^\n]s",input);

    char *token = strtok(input, " "); // Extract the first token

    //since token is a pointer it points to the whole word
    while(token != NULL){ // loop through the string to extract all other tokens
        Function(token); //accessing the function for each token
        //updating next token
        token=strtok(NULL," ");//strtok is string method for token
    }
    printf("\n%s\n", input);

    printf("Bye.\n");




}

void Function(char *x)
{
    int input =1;

    //Question i) To check input validity
    for(int i=0;i<strlen(x);i++) {
        switch (x[i]) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':input=0;
                break;

            default:input=1;
        }
        if(input==0) {
            printf("Numeric characters found, Invalid Entry\n");
            break;
        }
    }
    if(input==1)
        printf("Valid entry\n");

    //Question ii) To check input length
    printf("\nString has input length %d\n",strlen(x));

    //Question iii) To check input first character
    printf("\nThe first character in String is %c\n",x[0]);

    //Question iv) To check most frequent character
    //Making an array of count to count each instance
    int counter[strlen(x)];
    for(int i=0; i<strlen(x);i++){
        /*
         * Important this command is used to set the index of the counter to a particular character
         * therefore when that character appears, the counter is incremented
         */
         ++counter[x[i]];
    }

    //Finding the letter which was used the most
    int max=counter[0];
    int pos=0;
    for(int i=0; i<strlen(x);i++){
        if(counter[x[i]]>max){
            max=counter[x[i]];
            pos=i;
        }
    }

    printf("The max character is: %c \n", x[pos]);


}


