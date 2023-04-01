#include <stdio.h>

int main(void)

{

    int A3=1000,A4=1000,A5=1000;
    int input1,input2,input3;



    printf("Place your order\n");
    printf("Enter how many A3 packs you need\n");
    scanf("%d", &input1);

    printf("Enter how many A4 packs you need\n");
    scanf("%d", &input2);

    printf("Enter how many A5 packs you need\n");
    scanf("%d", &input3);


    printf("Ordered:\n %d A3 sheets\n %d A4 sheets\n %d A5 sheets",input1,input2,input3);
    printf("Left in stock:\n %d A3 sheets\n %d A4 sheets\n %d A5 sheets",(A3-input1),(A4-input2),(A5-input3));

    return 0;

}
