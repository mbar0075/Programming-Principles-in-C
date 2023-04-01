//Header file which allows main class to access methods of functionClass.c files

/*General types definition */
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


/*operation: initialises DataTable_t struct*/
/*preconditions: integer parameters choice,noofcols and noofrows */
/*               choice can be either 0 or 1 and noofcols and noofrows refer*/
/* to number of columns and rows in DataTabel_t struct respectively */
/*postconditions: The DataTable_t is initialised to empty */
DataTable_t *initDT(int choice , int noofcols,int noofrows);

/*operation: Frees the DataTable_t from memory*/
/*preconditions: DataTable_t pointer */
/*postconditions: Relinquishes all sources of DataTable_t*/
void deinitDT(DataTable_t *data);

/*operation: loads a csv file into the DataTable_t struct*/
/*preconditions: DataTable_t pointer */
/*postconditions: DataTable_t struct initialised with data from csv file */
void loadDT(DataTable_t *data);

/*operation: exports the contents of the DataTable_t struct into a csv file*/
/*preconditions: DataTable_t pointer */
/*postconditions: csv file contains data from DataTable_t struct*/
void exportDT(DataTable_t *data);

/*operation: prints DataTable_t struct contents*/
/*preconditions: DataTable_t pointer */
/*postconditions: DataTable_t struct is displayed */
void showDT(DataTable_t *data);

/*operation: Returns a copy of the DataTable_t with specific rows and columns*/
/*preconditions: DataTable_t pointer */
/*postconditions: pointer to new DataTable_t struct */
DataTable_t *projectDT(DataTable_t *data);

/*operation: Accepts a user defined function to transform columns*/
/*preconditions: DataTable_t pointer and 3 user defined function with types float,int and char* respectively */
/*postconditions: DataTable_t struct including transformed column */
void mutateDT(DataTable_t *data,float (*floatfunction)(float num,int change),int (*intfunction)(int num,int change),void (*stringfunction)(char* string,char strchange,char strreplace));

/*User defined function used for testing:*/
float floatnumbers(float num,int change);

/*User defined function used for testing:*/
int intnumbers(int num,int change);

/*User defined function used for testing:*/
void stringinput(char* string,char strchange,char strreplace);
