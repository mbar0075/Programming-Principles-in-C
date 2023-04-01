//Header file which allows main class to access methods of functionClass.c files
//Defining of constants
#define ROWS 1000
#define SSIZE 64
#define COLS 6

//Declaration of union location
typedef union{
    //Assigning an array of float
    float floatrows[ROWS];
    //Assigning a 2d array of char
    char stringrows[ROWS][SSIZE];
}location;

//Declaration of struct DataTable_t
typedef struct{
    //An array containing pointers setting it to type union location to have both float and character string pointers
    location *columns[COLS];
    //An integer to hold the number of populated rows
    int nrows;
    //2 integers to hold the start of the string columns and end of the columns
    int colstart,colend;
    //Assigning a 2d array of char to hold the labels
    char labels[COLS][SSIZE];
}DataTable_t;


//Declaring of methods:
//Declaration of method initDT with interger parameters choice
DataTable_t *initDT(int choice);
//Declaration of method deinitDT with DataTable_T pointer parameter
void deinitDT(DataTable_t *data);
//Declaration of method loadDT with DataTable_T pointer parameter
void loadDT(DataTable_t *data);
//Declaration of method exportDT with DataTable_T pointer parameter
void exportDT(DataTable_t *data);
//Declaration of method showDT with DataTable_T pointer parameter
void showDT(DataTable_t *data);
//Declaration of method projectDT with DataTable_T pointer parameter
DataTable_t *projectDT(DataTable_t *data);
//Declaration of method mutateDT with DataTable_T pointer and user defined functions as parameters
void mutateDT(DataTable_t *data,float (*floatfunction)(float num,int change),void (*stringfunction)(char* string,char strchange,char strreplace));

//User defined functions:
float floatnumbers(float num,int change);

void stringinput(char* string,char strchange,char strreplace);