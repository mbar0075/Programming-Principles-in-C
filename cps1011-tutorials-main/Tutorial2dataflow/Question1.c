/* rhodium.c  -- your weight in platinum        */

#include <stdio.h>

int main(void)

{

    float weight;    /* user weight            */

    int value;     /* platinum equivalent     */



    printf("Are you worth your weight in platinum?\n");

    printf("Let's check it out.\n");

    printf("Please enter your weight in pounds: ");



/* get input from the user                     */

    scanf("%f", &weight);

/* assume platinum is $1770 per ounce            */

/* 14.5833 converts pounds avd. to ounces troy */

    value = 1770.0 * weight * 14.5833;

    printf("Your weight in platinum is worth $%.4f.\n", value);
    printf("Your weight in platinum is worth $%.4d.\n", value);

    printf("You are easily worth that! If platinum prices drop,\n");

    printf("eat more to maintain your value.\n");

/*Question 1 i)
 * when 165 pounds weight is:
 *$4259053.00.
 *
 * ii)
 * When changed to double weight is:
 * $4259052.76
 *
 * iii) rounded to 4 decimal places
 *
 * iv)
 * when changed to int
 * using %f:
 * Your weight in platinum is worth $0.0000.
 * using %d:
 * Your weight in platinum is worth $4259052.
 */

//Example
char mytext[5];
scanf("%s",mytext);
 printf("%s",mytext);



    return 0;

}

