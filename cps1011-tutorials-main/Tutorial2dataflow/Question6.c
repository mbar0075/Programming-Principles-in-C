#include <stdio.h>

int main(void)

{

    float dollar[10],euro[10];

    printf("Conversion of Dollars to Euros \n");

    for (int i = 0; i <10 ; i++) {
        printf("Enter Dollar %d \n",i+1);
        scanf("%f",&dollar[i]);
        euro[i]=0.86*dollar[i];
        printf("$ %.2f in euro is %.2f\n",dollar[i],euro[i]);
    }


    return 0;

}

