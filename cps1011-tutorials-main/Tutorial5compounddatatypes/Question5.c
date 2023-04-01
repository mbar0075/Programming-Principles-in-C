//3D Array
#include <stdio.h>
#define SIZE 10

void function(double arr[SIZE][SIZE][SIZE]);
double f(int x, int y, int z);

int main(void) {
    //Declaration of loop
   double array[SIZE][SIZE][SIZE];

    function(array);

    return 0;
}

void function(double arr[SIZE][SIZE][SIZE]) {
    for(int i=0;i<=SIZE;i++){
        for(int j=0;j<=SIZE;j++){
            for(int k=0;k<=SIZE;k++){
                arr[i][j][k]=f(i,j,k);
                if(arr[i][j][k]>=0 && arr[i][j][k]<=100)
                    printf("%.2f\t",arr[i][j][k]);
                else
                    printf("X\t");
            }
            printf("\n");
        }
        printf("\n");
    }
}

double f(int x, int y,int z){
    return x+(6*y)+(7.2*z);
}