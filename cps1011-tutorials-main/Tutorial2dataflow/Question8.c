
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n,s;
    double sum=0;

    printf("Reimann zeta function, \nEnter Integer n\n");
    scanf("%d",&n);
    printf("Enter s(power)\n");
    scanf("%d",&s);

    for (int i = 1; i <=n ; i++) {
        sum+=pow(i,-s);
    }
    printf("The sum is: %.2f\n",sum);

    return 0;

}
