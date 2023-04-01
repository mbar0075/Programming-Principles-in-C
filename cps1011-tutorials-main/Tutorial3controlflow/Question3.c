#include <stdio.h>

int main(void)

{

    int pin=1234,tries=5,input;
    do {

        printf("Please enter pin , tries left: %d\n",tries);

        scanf("%d", &input);
        if(input==pin) {
            printf("Welcome\n");
            tries=0;
        }
        else
            tries--;
    } while(tries!=0);

    if(input!=pin)
        printf("You have been logged out for entering the pin wrong for 5 times\n");
    return 0;

}

