#include <stdio.h>

int main(void)

{

    float income,tax=0,temp;
    char input1,input2;
    float taxbracket;

    printf("Taxes Calculation Program\nPlease enter your income \n");
    scanf("%f", &income);
    temp=income;

    printf("Do you work for the ICT industry enter y if yes\n");
    scanf("%c\n", &input1);

    printf("\nDo you collect old electronic equipment for green disposal enter y if yes\n");
    scanf("%c\n", &input2);

    //v)
    if(input2=='y')
        taxbracket=15000;
    else
        taxbracket=10000;


    //i)
    if(temp>=taxbracket) {
        tax += taxbracket * 0.18;
        temp=temp-taxbracket;
        //ii)
        if(temp>=8000) {
            tax += 8000 * 0.2;
            temp=temp-8000;
            //iii)
            tax+=temp*0.25;
        }
        else if(temp<8000) {
            tax+=temp*0.2;
        }
    }
    else if(temp<taxbracket) {
        tax+=temp*0.18;
    }
    //iv)
    if(input1=='y')
        tax=tax-(tax*0.05);

    printf("The Tax is : %.2f euros",tax);
    return 0;

}

