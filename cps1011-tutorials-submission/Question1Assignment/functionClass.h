//Header file which allows main class to access methods of functionClass.c files
//Declaration of struct freq and assigning 2 int values, value and frequency
typedef struct {
    int value;
    int frequency;
}freq;
//Declaration of method init_array with array parameter
int init_array(int array[]);
//Declaration of method display with integer and array parameter
void display(int size,int array[]);
//Declaration of method reverse with integer and 2 array parameter
int *reverse(int *arr1,int *arr2 ,int size);
//Declaration of method frequency with integer array and struct freq array parameter
void frequency(int arr[],freq pairs[]);
//Declaration of method display_freq with struct freq array parameter
void display_freq(freq pairs[]);