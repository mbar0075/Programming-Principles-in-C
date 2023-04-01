#include <stdio.h>

int main(void)

{
    int count=0;

    //To set count
    while(count>20 ||count<1) {
        printf("Please enter how many numbers you wish to enter\n");
        scanf("%d", &count);
    }

    int num[count],sum=0;
    double mean,median;

//To populate array
    for(int i=0;i<count;i++) {
        printf("Please enter non-unique number %d\n",i+1);
        scanf("%d", &num[i]);
        sum+=num[i];
    }

    for(int i=0;i<count;i++) {
        for(int j=0;j<count;j++) {
            if(num[i]<num[j]){
                int temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
    }
    for(int i=0;i<count;i++) {
        printf(" %d\n",num[i]);
    }
//To get mode
    int maxCount=0,counter,mode;
    for(int i=0;i<count;i++) {
        for(int j=0;j<count;j++) {
            if(num[i]==num[j])
                counter++;
        }
        if(maxCount<counter) {
            maxCount = counter;
            mode=num[i];
        }
    }

    mean=(double)sum/count;
    printf("The mean is %.2f\n",mean);
    median=(num[(int)(count/2)]+num[((int)(count/2)+1)])/2;
    printf("The median is %.2f\n",median);
    printf("The mode is %d\n",mode);

    return 0;

}

