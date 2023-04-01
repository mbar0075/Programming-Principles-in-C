#include <stdio.h>

int main(void) {

//to have a string array , 5 has to become before
    char name[5][256],surname[5][256];
    int age[5],count;
    float salary[5],yearlysalary[5],sum,avgsalary;//first salary is 0

    for(int i=0; i<5;i++) {
        printf("Enter name %d\n",i+1);
        scanf("%s", name[i]);

        printf("Enter surname %d\n",i+1);
        scanf("%s", surname[i]);

        printf("Enter age %d\n",i+1);
        scanf("%d", &age[i]);

        printf("Enter pay-cheque salary %d\n",i+1);
        scanf("%f", &salary[i]);

        sum+=salary[i];
        yearlysalary[i]=salary[i]*12;
}
    printf("counter\t\tname\t\tsurname\t\tage\t\tsalary\t\tyearly salary\n");
    for(int i=0;i<5;i++) {
    printf("%d\t\t%-8.10s\t\t%-8.10s\t\t%d\t\t%.2f\t\t%.2f\n", i+1, name[i], surname[i], age[i], salary[i],yearlysalary[i]);
    //7 is minimum field width , first part is padding(truncating string) second part is precision
}
    avgsalary=sum/5;
    printf("Average salary is%.2f ",avgsalary);
    return 0;

}

