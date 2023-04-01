/* echo_eof.c -- repeats input to end of file */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)

{

    char text[100];
    int check =1,count=0;
    printf("Input text stream enter\n");
    scanf("%[^\n]s",text);

    //Question i)
    for(int i=0; i<strlen(text);i++){
        if(text[i]=='-') {
            check=0;
        }
    }
    if(check==1){
        printf("Warning word doesn't have a hyphen\n");
        count++;
    }

    if(strlen(text)>10) {
        printf("Warning word is larger than 10\n");
        count++;
    }
    //Question ii)
    for(int i=1; i<strlen(text);i++) {
        char temp= toupper(text[i]);
        if ((temp>=65 && temp<=90)) {
            if (text[i] == toupper(text[i])) {
                printf("Your text has an uppercase letter beyond character 1\n");
                count++;
            }
        }
    }

    //Question iii)
    char temp= toupper(text[0]);
    if (!(temp>=65 && temp<=90)) {
        printf("Your text starts with a non-alphabetic character\n");
        count++;
    }

    //Question8
    int check2;
    for(int i=0; i<strlen(text);i++) {
        char temp2= text[i];
        check2=1;
        /*To check if String array is being populated
         * printf("Character %c\n",text[i]);
         */
        switch(temp2){
            case '(':
            case ')':
            case '.':
            case ';':
            case ':':
            case ',':
            case '"':
            case '!':
            case '@':
            case '?': check2=0;
                        break;
            default:
                break;
            }

        if (check2==0 && text[i-1]==(char)(32)) {
                printf("Your text has a punctuation preceded by a space\n");
                count++;
        }
    }

    for(int i=1; i<strlen(text);i++) {
        if (text[i]==' '&& text[i+1]==' ') {
            printf("There are repeated spaces\n");
            count++;
        }
    }

    //Question iv)
    printf("Found %d error/s\n",count);


    return 0;


}
