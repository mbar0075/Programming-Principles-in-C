#include <stdio.h>

int main(void) {

    char choice, confirm;
    int code[5] = {1, 2, 3, 4, 5},index[5];
    char name[5][20] ={"pepsi","milk","bread","pasta","pizza"};
    double price[5]={1.5,0.5,0.7,0.8,2},total;
    do {

        printf("Choose from the following options\n1.Add items to shopping cart\n2.Show current total\n3.Checkout\n4. Cancel session\nq. Quit");
        scanf("\n%c", &choice);
        switch (choice) {
            case '1':printf("\nEnter the code name to add to shopping cart:\ncode\t\tname\t\tprice\n");
                for(int i=0; i<5;i++) {
                    printf("%d\t\t %s\t\t%.2f\n",code[i],name[i],price[i]);
                }
                scanf("%d %d %d %d %d",&index[0],&index[1],&index[2],&index[3],&index[4]);
                for(int i=0; i<5;i++) {
                    for(int j=0; j<5;j++) {
                        if(index[i]==code[j])
                            total+=price[j];
                    }
                }
                break;
            case '2':printf("The current total is : %.2f\n",total);
                break;
            case '3':
                for(int i=0; i<5;i++) {
                    for(int j=0; j<5;j++) {
                        if(index[i]==code[j])
                           printf("%d\t\t %s\t\t%.2f\n",code[j],name[j],price[j]);
                    }
                }
                printf("The current total is : %.2f\n",total);

                printf("\nDo you want to start a new session?,confirm entry by pressing:y\n");
                scanf("\n%s", &confirm);
                if (confirm == 'y') {

                    printf("\nStarting new sessions....\n");
                    total=0;
                    printf("\nTotal= %.2f\n",total);
                    break;
                } else
                    break;

            case '4':
                printf("\nConfirm entry by pressing:y\n");
                scanf("\n%s", &confirm);
                if (confirm == 'y') {
                    printf("\nCancelled current order....\n");
                    total=0;
                    printf("\nTotal= %.2f\n",total);
                    break;
                } else
                    break;

            case 'q':
                printf("\nConfirm entry by pressing:y\n");
                scanf("\n%s", &confirm);
                if (confirm == 'y') {
                    printf("\nGoodbye\n");
                    choice = 'q';
                    break;
                } else
                    break;

            default:
                printf("\nRe-enter option\n");
        }
    } while (choice != 'q');
    return 0;
}



