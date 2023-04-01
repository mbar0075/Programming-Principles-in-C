
#include <stdio.h>
#include <string.h>
#include "ObjectClass.h"

void Conversion(int n);

void Reverse(char *x, int begin, int end);


void Question4(void)

{



    //Question i)
    int num;

    printf("Decimal Conversion\nEnter a decimal value  (q to quit):\n");
    while (scanf("%d", &num) == 1)

    {

        printf("\nConversion of decimal number %d into hexadecimal :",num);
        Conversion(num);



        printf("\nEnter a value in the range 0-12 (q to quit):\n");
    }

    //To clear buffer
    fflush(stdin);

    //Question ii)
    char input[100];
    printf("String Reversal\nEnter word\n");
    scanf("\n %s",input);

    Reverse(input, 0, strlen(input)-1);
    printf("%s\n", input);

    printf("Bye.\n");


}


void Conversion(int n)   // hex conversion
{
    char output;
    if ( n>0) {
        switch(n%16){   //Switch statement to transform numbers into hexadecimal characters
            case 10:output='A';
                    break;
            case 11:output='B';
                break;
            case 12:output='C';
                break;
            case 13:output='D';
                break;
            case 14:output='E';
                break;
            case 15:output='F';
                break;
            default:output=n%16+'0'; // Added 0 to convert an int to a character
        }
        Conversion(n/16);
        printf("%c",output);
    }
}


//Method to reverse String
void Reverse(char *x, int begin, int end)
{
    //Declaring character which will be used as a temporary placeholder for swapping
    char c;

    //When the middle of the list is reached and thus the elements were swapped
    if (begin >= end)
        return;

    //Swapping characters
    //* used as pointer
    c          = *(x+begin);
    *(x+begin) = *(x+end);
    *(x+end)   = c;

    Reverse(x, ++begin, --end);
    //No return needed since String is passed by reference
}



