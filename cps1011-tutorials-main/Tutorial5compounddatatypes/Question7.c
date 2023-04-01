#include <stdio.h>
#include <string.h>

int main(void)
{
    int amount;

    printf("Please input how many words you will enter");
    fflush(stdout);
    scanf("%d",&amount);

    char text[amount][20];

    for(int i=0;i<amount;i++) {
        printf("Please input word %d", i+1);
        fflush(stdout);
        scanf("%s", text[i]);
    }

    printf("Please input a suffix to add to the text");
    fflush(stdout);
    char suffix[10];
    scanf("%s",suffix);

    int size2 = strlen(suffix);

    for(int i=0;i<amount;i++) {
        int size = strlen(text[i]);

        for(int x=0;x<=size2;x++){
            if(suffix[x]=='\n'){
                break;
            }
            text[i][size+x]=suffix[x];
        }
    }

    for(int i=0;i<amount;i++) {
        printf("%s\n",text[i]);
        fflush(stdout);
    }

    return 0;
}