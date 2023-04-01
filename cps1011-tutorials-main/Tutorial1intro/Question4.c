#include <stdio.h>

//Important to declare before main
void add(int num1, int num2);

void subtract(int num1, int num2);

void multiply(int num1, int num2);

//Main Method
int main(void) {
    int num1,num2;
    printf("Enter num1\n");
    scanf("%d",&num1);
    printf("Enter num2\n");
    scanf("%d",&num2);
    //Display
    add(num1,num2);

    subtract(num1,num2);

    multiply(num1,num2);
    return 0;

}

//Addition method
void add(int num1, int num2) {
    int ans=num1+num2;
    printf("Addition:%d \n",ans);
}

//Subtracting method
void subtract(int num1, int num2) {
    int ans;
    if (num1 > num2) {
        ans = num1 - num2;
        printf("Subtracting %d from %d is %d \n",num2,num1,ans);
    }
    if (num2 > num1) {
        ans = num2 - num1;
        printf("Subtracting %d from %d is %d \n", num1, num2, ans);
    }
}

//Multiply method
void multiply(int num1, int num2) {
    int ans=num1*num2;
    printf("Multiplying %d * %d =%d",num1,num2,ans);
}
