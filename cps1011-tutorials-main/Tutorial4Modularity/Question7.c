#include <stdio.h>
#include "ObjectClass.h"

double Ceil2(double n);

double Floor2(double s);


void Question7(void)

{

    double num;



    printf("Enter number\n");
    scanf("%lf", &num);

    double result=Ceil2(num);//Passing by reference
    printf("The ceiling (rounding up):ceil(%.2lf) is  %.2lf\n",num,result);
    result=Floor2(num);
    printf("The Floor (rounding down):floor(%.2lf) is  %.2lf\n",num,result);

    printf("Bye.\n");



}

double Ceil2(double n){
    double result=(int)(n)+1;
    return result;

}

double Floor2(double s)

{
    double result =(int)(s);
    return result;

}


