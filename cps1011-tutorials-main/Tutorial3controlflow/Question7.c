/* echo_eof.c -- repeats input to end of file */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)

{

    char text[100];
    int check =1,count=0;
   printf("Input text stream enter\n");
    scanf("%s",text);

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

    //Question iv)
    printf("Found %d errors\n",count);
    return 0;

    //Question v)

}
