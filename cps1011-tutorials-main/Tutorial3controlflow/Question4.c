#include <stdio.h>

int main(void)

{

    for (int i = 1; i <=100 ; i++) {
        printf("%d\t",i);
        if(i%10==0)
            printf("\n");
    }

    return 0;

}

