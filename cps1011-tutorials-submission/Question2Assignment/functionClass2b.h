//Header file which allows main class to access methods of functionClass.c files

//Declaration of union location
typedef union{
    //Assigning a float value
    float floatrows;
    //Assigning an integer value
    int introws;
    //Assigning a pointer to a char array
    char *stringrows;
}location;

//Declaration of struct DataTable_t
typedef struct{
    //A pointer to an array containing pointers to union location to have both float, integer and character string values
    location **columns;
    //An integer to hold the number of populated rows
    int nrows;
    //A pointer pointing to strings (i.e. char*)
    char **labels;
    //An array containing the column types
    int *coltype;
    //An integer to hold the number of populated columns
    int ncols;
}DataTable_t;


//Declaring of methods:
//Declaration of method initDT with interger parameters choice,noofcols and noofrows
DataTable_t *initDT(int choice , int noofcols,int noofrows);
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
void mutateDT(DataTable_t *data,float (*floatfunction)(float num,int change),int (*intfunction)(int num,int change),void (*stringfunction)(char* string,char strchange,char strreplace));

//User defined functions:
float floatnumbers(float num,int change);

int intnumbers(int num,int change);

void stringinput(char* string,char strchange,char strreplace);
