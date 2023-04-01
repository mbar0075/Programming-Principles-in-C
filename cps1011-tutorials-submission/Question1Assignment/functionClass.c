//functionClass file which includes methods to be used by runner file
//Libraries used in the program:
#include <stdio.h>
//Header file used in the program:
#include "functionClass.h"
//Defining of constant size
#define SIZE 200

//Method init_array with array parameter passing
int  init_array(int array[]) {
    int stop=1;//Declaring of variable stop which be used as a stopping condition for the loop
    int count=0;//Declaring variable count which will be used to find the size
    float temp;//Declaring of variable temp
    printf("Enter a series of numbers, max is 200,numbers Enter a 0 to quit\n\n");
    //Creating a variable c of type char in case user inputted a character instead of an int
    char c;
    do{
        do {
            //Inputting statements:
            printf("Enter Element %d :\n",count+1);
            scanf("%f", &temp);
            /*float is being used as an input in case user enter decimal point value,
             * typecasting it being done to transform this value as int and storing it in array[i]
             */
            array[count]=(int)(temp);
            //Variable c is being used in case user enters character
            c=getchar();
            //If user types 0 which is the stopping condition or the array[count]=0, count is decremented to not
            //include last element and stop is initialised to 0, and the program breaks from the inner loop
            if(array[count]==0){
                count--;
                stop=0;
                break;
            }
            //Breaking out of loop and initialising  stop to 0 when count is equal to 200,
            // since 200 is the max amount of numbers user can input
            if(count==SIZE-1){
                stop=0;
                break;
            }
        //do while loop being used to catch when a user inputted a character, and the user would have to re-enter element
        }while(c!='\n');
        //Incrementing count
        count++;
    //Do while loop quits when user enters q or max amount of numbers entered is reached
    }while(stop!=0);
    //If count is not equal max and the last element is not 0 already, then we set the last element as 0 to signify end of array
    if((count!=200 )&&( array[count]!=0)) {
        array[count + 1] = 0;
    }

    return count;
}

//Method display with size and array parameter passing
void display(int size,int array[]){

            //Utilised print statements to print the required format output
            //In some cases I had to use %(number of characters before output)s, to reference strings
            //in order to obtain the required output indentation
                printf("{\n");
                printf(" %10s: [\n","\"array\"");
                for (int i = 0; i < size; i++) {
                printf("%8s\n","{");
                printf("%17s:\"%.2d\",\n","\"offset\"", i);
                printf("%16s:\"%.2d\"\n","\"value\"", array[i]);
                if(i!=size-1)
                    printf(" %8s\n\n","},");
                else
                    printf(" %8s\n","},");
                }
                printf("%4s\n","]");
                printf("}");

}

//Method reverse with size and 2 array parameter passing
int *reverse(int *arr1, int *arr2, int size) {
    //Declaring of variable count and setting it to size-1, since last element entered is escape element -1
    int count=size-1;
    for(int i=0;i<=size;i++) {
        //values of array 1 are placed in array 2
        arr2[count]=arr1[i];
        //Count is decremented, since it is being used as an index for the reverse array
        //and the goal is for the first element in arr1 to become the last element of arr2
        count--;
    }
    //Returning of arr2
    return arr2;
}

//Method frequency with  array and struct freq array parameter
void frequency(int arr[],freq pairs[]){
    int size=0;//Declaring of variable size and setting it to 0

        for (int i = 0; i <= size; i++) {//Using a for loop to find out the size of the array
            if (arr[i] !=0)//if element in array is 0 this is the stopping condition and variable size stops incrementing
                size += 1;
            else{//When the element is 0, breaks from loop
                size+=1;
                break;
            }
            if(size==200)//To check if size is max, if it is break
                break;
        }


    int psize=0;//Declaring of variable psize to measure size of pairs array and setting it to 0

    int check;//Declaring of variable check
    for(int i=0;i<size;i++) {//Using a for loop to go through all the elements in the array arr
        check=0;//Setting variable check to 0
        for(int j=0;j<psize;j++) {//Using a for loop to go through all the elements in the array pairs
            if(arr[i]==(pairs[j].value)) {//Checking whether the value of the array arr is inside the pairs array
                check=1;//Setting check = 1 when the element in array arr was found in pairs array
            }
        }
        /*Whilst going through all the elements in pairs array, if the elements wasn't found therefore
         * check will remain 0 signifying that we need to add the element in the pairs array*/
        if(check==0){
            pairs[psize].value = arr[i];//Adding element to pairs array
            pairs[psize].frequency=0;//Setting the frequency of that element to 0 which will later be incremented
            psize += 1;//Incrementing psize since a new element was added to pairs array
        }
    }

    for(int i=0;i<size-1;i++) {//Using a for loop to go through all the elements in the array arr
        int temp = arr[i];
        for (int j = 0; j < psize; j++) {//Using a for loop to go through all the elements in the array pairs
            if (temp == (pairs[j].value)) {//Checking whether the value of the array arr is inside the pairs array
                pairs[j].frequency += 1;//Incrementing frequency when the value of array arr appears in the pairs array
            }
        }
    }

    //Setting value as -1 and frequency as 0 to signify end of array
    pairs[psize].value=-1;
    pairs[psize].frequency=0;

}

//Declaration of method display_freq with struct freq array parameter
void display_freq(freq pairs[]){
    int size=1;//Declaring of variable size and initialising it to 1
    //For loop and if statement used to find size of array, if a null is encountered the variable size will stop incrementing

    //Using a for loop to find out the size of the pairs array
    for(int i=0;i<size;i++) {
        //If frequency!=0 and value!=-1,end of array has not been reached and thus size is incremented
        if ((pairs[i].frequency != 0) && (pairs[i].value != -1)) {
            size++;
        }//If frequency=-1 and value=-1, end of array is reached and thus size is decrementing to not count this instance
        else
            size--;
    }

    //Sorting the array in ascending order for value
    freq temp;//Creating a variable called temp of type freq which will be used to swap the elements
    for (int top = 0; top < size-1; top++) {//Outer loop used to loop through all the elements in the pairs array with index top
        for (int seek = top + 1; seek < size; seek++) {//Inner loop used to loop through the elements
            // which have an index of top+1

            //Comparing elements from the first loop with the second loop
            if (pairs[top].value > pairs[seek].value) {
                //Swapping the elements
                temp = pairs[top];
                pairs[top] = pairs[seek];
                pairs[seek] = temp;
            }
        }

    }
                //Utilised print statements to print the required format output
                //In some cases I had to use %(number of characters before output)s, to reference strings
                printf("{\n");
                printf(" %10s: [\n","\"array\"");
                for (int i = 0; i < size; i++) {
                    printf("%8s\n","{");
                    printf("%17s:\"%.2d\",\n","\"offset\"", i);
                    printf("%16s:\"{%d , %d}\"\n","\"value\"", pairs[i].value, pairs[i].frequency);
                    if(i!=size-1)
                        printf(" %8s\n\n","},");
                    else
                        printf(" %8s\n","},");
                }
                printf("%4s\n","]");
                printf("}");

}