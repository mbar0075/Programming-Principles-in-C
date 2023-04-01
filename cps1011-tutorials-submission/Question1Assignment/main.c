//Runner file
//Libraries used in the program:
#include <stdio.h>
//Header file used in the program:
#include "functionClass.h"
//Defining of constant size
#define SIZE 200


//Declaration of Main Menu function with parameters
void MainMenu(int size, int arr1[],int arr2[],freq pairs[]);

int main(void) {
    //Declaring array variables which will be used throughout the menu options
    int arr1[SIZE];
    int arr2[SIZE];
    int size=SIZE;
    freq pairs[SIZE];

    //Calling MainMenu method and passing the values by reference in case of arrays and passing by values in case of size
    MainMenu(size,arr1,arr2,pairs);
    return 0;
}


//MainMenu method
void MainMenu(int size, int *arr1, int *arr2,freq pairs[]) {
    //Declaring the user input which will be used as an input for the menu, declaring it as type char to accept 'q' as a termination of the menu
    char choice;
    //Declaring variable check to be used to check whether option 1 was executed, since option 1 needs to be executed before the other options
    int check=0;
    //Declaring variable check to be used to check whether option 4 was executed, since option 4 needs to be executed before option 5
    int check2=0;

    do {
        //Printing of Menu
        printf("\n\nChoose from the following Menu:\n1.Initialise Array\n2.Display Array\n3.Reverse Array\n4.Frequency\n5.Display Frequency\nq. Quit\n\n");
        //User Input
        scanf("\n%c", &choice);
        //getChar to clear the buffer
        while(getchar()!='\n');
        //Using of switch statement to check all the options
        switch (choice) {

            //Since choice is of type char cases had to be done in single inverted commas
            case '1'://Option 1 calling function init_array from functionClass.c and returning contents of the function into variable size
                    size=init_array(arr1);
                    check=1;//Changing contents of variable check since option 1 was executed
                    check2=0;//When the user would want to reinitialise the array, option 4 would need to be reset
                    //and thus check2 is initialised to 0
                break;

            case '2': //Checking if option 1 was executed before, if not then executing from current option
                if (check == 0) {
                    printf("\nError Need to execute option 1 Before\n");
                    break;
                } else {
                    //Option 2 calling function display from functionClass.c
                    display(size, arr1);
                }
                break;

            case '3'://Checking if option 1 was executed before, if not then executing from current option
                if (check == 0) {
                    printf("\nError Need to execute option 1 Before\n");
                    break;
                } else {
                    //Option 3 calling function reverse from functionClass.c and returning contents of the function into variable arr2
                    arr2 = reverse(arr1, arr2, size);
                    //Calling function display to print arr2
                    display(size, arr2);
                }
                break;

            case '4'://Checking if option 1 was executed before, if not then executing from current option
                if (check == 0) {
                    printf("\nError Need to execute option 1 Before\n");
                    break;
                } else {
                    //Option 4 calling function frequency from functionClass.c
                    frequency(arr1, pairs);
                    check2=1;//Changing contents of variable check2 since option 1 was executed
                }
                break;

            case '5'://Checking if option 4 was executed before, if not then executing from current option
                if (check2 == 0) {
                    printf("\nError Need to execute option 4 Before\n");
                    break;
                } else {
                    //Option 5 calling function display_freq from functionClass.c
                    display_freq(pairs);
                }
                break;

            case 'q'://Option q Quitting from the Menu and displaying Goodbye message
                    printf("\n\nGoodbye\n\n");
                break;

                //In case an invalid option is entered an invalid message is displayed
            default:printf("\n\nRe-enter option\n\n");
                break;

        }
        //Do while loop used to loop the Menu until the user decides to quit
    } while (choice != 'q');
}
