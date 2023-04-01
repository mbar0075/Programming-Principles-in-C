#include <stdio.h>//Search from some standards include path
#include "ObjectClass.h"//Include a header file

int main(void) {

    char choice;
    do {

        printf("Choose from the following:\n1.Question1\n2.Question2\n3.Question3\n4.Question4\n5.Question5\n6.Question6\n7.Question7\nq. Quit");
        scanf("\n%c", &choice);
        switch (choice) {
            case '1': Question1();
                break;
            case '2':Question2();
                break;
            case '3':Question3();
                break;
            case '4':Question4();
                break;
            case '5':Question5();
                break;
            case '6':Question6();
                break;
            case '7':Question7();
                break;
            case 'q':printf("\nGoodbye\n");
                break;
            default:printf("\nRe-enter option\n");
                break;
        }
    } while (choice != 'q');

    return 0;
}



