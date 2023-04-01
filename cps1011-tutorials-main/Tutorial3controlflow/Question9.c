/* echo_eof.c -- repeats input to end of file */
#include <stdio.h>

int main(void){
    int num;
    int stop = 0;

    FILE *fp;
    fp = fopen("Output.txt","a"); //Opens the file a=append/w=write
    //File created automatically by program

    do {
        printf("Please input a number between 0 and 100\n");

        if (scanf("%d", &num) != 1) {
            printf("Invalid Input\n");
            while (getchar() != '\n');//clears buffer
            stop=1;
        }
        else if (num>=0 && num<=100) {
            fprintf(fp,"%d\n",num);
        }
        else if(num>100 || num<0){
            printf("Invalid Input\n");
        }
        else{
            stop=1;
        }
    }while(stop!=1);

    fclose(fp);//closes the file
    return 0;
}