#include <stdio.h>
#include <math.h>
#include "ObjectClass.h"

double Ceil1(double *num);

double Floor1(double *num);

void Question6(void)

{

    double num;



    printf("Enter number\n");
    scanf("%lf", &num);

    double result= Ceil1(&num);
    printf("The ceiling (rounding up):ceil(%.2lf) is  %.2lf\n",num,result);
    result=Floor1(&num);
    printf("The Floor (rounding down):floor(%.2lf) is  %.2lf\n",num,result);
    printf("Bye.\n");



}

double Ceil1(double *num)//*n address
{
    double result =ceil(*num);
    return result;

}

double Floor1(double *num)

{
    double result =floor(*num);
    return result;


}


