#include <stdio.h>


int main(int argc,char *argv[])//Integers stored in : char *argv[]
{
    int count,num1,num2;
    //Gives how many arguments you have
    printf("The command line has %d arguments :\n",argc-1);

    //To print the arguments
    for (count = 1; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");

    //Since input is already entered in the command-line
    sscanf(argv[1],"%d",&num1);//argv[1] is a pointer , and will be stored in num1
    sscanf(argv[2],"%d",&num2);

    printf("The total of %d and %d is %d",num1,num2,num1+num2);
    //To enter command-line via terminal:
    //1. type cd cmake-build-debug
    //2. type ./(Program name without .c) argument1 argument2
    return 0;
}