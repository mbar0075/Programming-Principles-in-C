
#include <stdio.h>

int main(void)
{
int days[10],weeks=7;

for(int i=0;i<10;i++) {
    printf("Input days %d\n",i+1);
    scanf("%d",&days[i]);
    printf( "%d weeks and %d days\n",days[i]/weeks, days[i]%weeks);
}
    return 0;

}
