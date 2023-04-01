#include <stdio.h>

int main(void)

{
    printf("Hello World\nWelcome\n");
    int dogs;



    printf("How many dogs do you have?\n");

    scanf("%d", &dogs);

    printf("So you have %d dog(s)!\n", dogs);
//Question ii)
    int cats;
    printf("Enter how many cats you have\n");
    scanf("%d",&cats);
    int animals=cats+dogs;
    printf("so you have %d animals\n",animals);
    return 0;

}
