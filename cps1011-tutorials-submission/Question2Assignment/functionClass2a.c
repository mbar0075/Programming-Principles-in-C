//functionClass file which includes methods to be used by runner file
//Libraries used in the program:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Header file used in the program
#include "functionClass2a.h"
//Defining of constants
#define COLS 6
#define SSIZE 64
#define ROWS 1000

//Declaration of method initDT with interger parameters choice
DataTable_t *initDT(int choice) {
    //Declaration of DataTable_t pointer
    DataTable_t *data;
    //If choice is 0 , then the DataTable is initialised from a file
    if(choice==0) {
        //Declaration of array of pointers of type location
        location *assignmemory[COLS];

        //Creating size in heap for DataTable_t
        data = (DataTable_t *) malloc(sizeof(DataTable_t));

        //Creating size in heap for data->columns through assignmemory array
        for (int i = 0; i < COLS; i++) {
            assignmemory[i] = (location *) malloc(sizeof(location));
            data->columns[i] = assignmemory[i];
        }

        //Utilising a for loop for the user to input labels and storing the user input in data->labels array
        for (int i = 0; i < COLS; i++) {
            char tmp[SSIZE];
            printf("Enter label %d", i + 1);
            scanf("%s", tmp);
            //Utilising the strcpy to copy the contents of tmp into data->labels[i]
            strcpy(data->labels[i], tmp);
        }
        data->colstart=3;
        data->colend=COLS;
    }
//If choice is 1 , then the DataTable is initialised from an already existing Datatable to have specific rows and columns
    else if(choice==1) {
        //Declaration of array of pointers of type location
        location *assignmemory[COLS];

        //Creating size in heap for DataTable_t
        data = (DataTable_t *) malloc(sizeof(DataTable_t));
        //Creating size in heap for data->columns through assignmemory array
        for (int i = 0; i < COLS; i++) {
            assignmemory[i] = (location *) malloc(sizeof(location));
            data->columns[i] = assignmemory[i];
        }
    }
    //Returning DataTable_t pointer
    return data;
}

//Declaration of method deinitDT with DataTable_T pointer parameter
void deinitDT(DataTable_t *data){

    //Freeing the data->columns from memory
    for( int i=data->colstart;i<data->colend;i++){
        free(data->columns[i]);
    }
    //Freeing the DataTable_t from memory
    free(data);

}

//Declaration of method loadDT with DataTable_T pointer parameter
void loadDT(DataTable_t *data){
    //Declaration of file pointer fptr
    FILE *fptr;
    //Opening the file in reading mode
    if((fptr=fopen("TestingFILE.csv","r"))==NULL)
    {
        //If file is not found an Error message is presented
        printf("Error file not found");
    }
    else {
        //Declaring of variable tmp to act as a temporary string
        char tmp[SSIZE];
        //Declaring variable rows
        int rows = 0;
        //Reading one line from file
        while (fgets(tmp, SSIZE, fptr) != NULL) {
            //Declaring of variable line to hold the current line read from file
            char *line;
            //Declaring variable to hold the position of string tmp
            int pos = 0;
            //While loop used to check if end of string is reached
            while (tmp[pos] != '\0') {
                //If character is \, then we transpose it to \. to not be influenced by strtok later on
                if (tmp[pos] == '\\' && tmp[pos + 1] == ',') {
                    tmp[pos] = '\\';
                    tmp[pos + 1] = '.';
                }
                //Incrementing position
                pos++;
            }

            //Separating the text read form file into tokens, each token is separated by a , since it is a CSV file
            line = strtok(tmp, ",");
            //Declaring variable cols to act as a counter for the columns in the DataTable_t
            int cols = 0;
            //While loop being used to check if end of line was not reached
            while (line != NULL) {
                //Utilising function atof to transpose token line into float
                float ret = atof(line);
                //Checking if variable ret !=0, since an atof of a string token would be 0 else token is a string
                if (ret != 0.0) {
                    //Storing float in data->columns[cols]->floatrows[rows]
                    data->columns[cols]->floatrows[rows] = ret;
                } else {
                    //Initialising variable to 0
                    pos = 0;
                    //While loop used to check if end of string is reached
                    while (line[pos] != '\0') {
                        //If character is \. then we transpose it to ,
                        if (line[pos] == '\\' && line[pos + 1] == '.') {
                            line[pos] = ',';
                            line[pos + 1] = ' ';
                        }
                        //Incrementing position
                        pos++;
                    }


                    strcpy(data->columns[cols]->stringrows[rows], line);
                }
                //Incrementing cols
                cols++;
                //Updating the location of the next token
                line = strtok(NULL, ",");
            }
            //Incrementing rows
            rows++;
        }
        //Closing the file
        fclose(fptr);
        //Setting the number of populated rows to rows counter;
        data->nrows = rows;
    }
}

//Declaration of method exportDT with DataTable_T pointer parameter
void exportDT(DataTable_t *data){
    //Declaration of file pointer fptr
    FILE *fptr;
    //Opening the file in writing mode
    fptr=fopen("OutputFile.csv","w");
    //Declaration of char array temp and initialising it all to null
    char temp[ROWS]={'\0'};


    //Looping through all the populated rows
    for(int i=0;i<data->nrows;i++){
        //Looping through all the populated columns
        for(int j=0;j<data->colend;j++) {
            if(j<data->colstart){
                //Declaration of char array text
                char text[ROWS];
                //Transforming the float into string using gcvt
                gcvt(data->columns[j]->floatrows[i],4,text);
                //Appending the float to the string text
                strcat(temp,text);
                //Appending a , to the string to signify end of entity
                strcat(temp,",");
            }
            else{
                //Creating a string words to hold data->columns[j]->stringrows[i]
                char *words=data->columns[j]->stringrows[i];
                //Declaring variable to hold the position of string tmp
                int pos=0;
                //While loop used to check if end of string is reached
                while(words[pos]!='\0'){
                    //If character is , then we transpose it to \,
                    if(words[pos]==','&&words[pos+1]==' '){
                        words[pos]='\\';
                        words[pos+1]=',';
                    }
                    //Incrementing position
                    pos++;
                }
                //Appending the words to the string temp
                strcat(temp,words);
                //If statement being used to append a , to the string temp to signify end of entity, besides when final column is reached
                if(j!=data->colend-1) {
                    strcat(temp, ",");
                }
            }
        }

        //Printing to file the string temp
        fprintf(fptr, "%s", temp);
        //Printing \n to file to indicate a new row in case there wasn't
        if(temp[strlen(temp)-1]!='\n'){
            //Printing to file the string temp
            fprintf(fptr, "%s", "\n");
        }
        //Clearing contents of string temp
        memset(temp,'\0',sizeof(temp));
    }

    //Closing the file
    fclose(fptr);
}

//Declaration of method showDT with DataTable_T pointer parameter
void showDT(DataTable_t *data){
    //For loop being used to show the labels
    printf("\t");
    for(int i=0;i<data->colend;i++) {
        printf("%-10.10s\t", data->labels[i]);
    }
    printf("\n");
    //If number of rows is smaller than 10 than ten than temp holds data->nrows
    //Else temp is set to hold 10
    int temp;
    if(data->nrows>10){
        temp=10;
    }else {
        temp = data->nrows;
    }
    //For loop being used to print the first 10 rows and all columns
    for(int j=0;j<=temp;j++) {
        //Displaying the row numbers
        if(j!=temp) {
            printf("%d\t", j + 1);
        }
        for(int i=0;i<data->colend;i++) {
            //if the final row is reached .... are printed else data->columns[i]->floatrows[j] is printed
            if(j==temp){
                printf(".................");
            }
            else if(i<data->colstart){//Displaying the float rows
                printf("%-10.2f\t", data->columns[i]->floatrows[j]);
            }
            else{//Displaying the string rows
                printf("%-10.10s\t", data->columns[i]->stringrows[j]);
            }
        }
        printf("\n");
    }
    //Printing the number of the last row
    printf("%d\t",(int)data->nrows);
    //Looping through all the columns in the last row
    for(int i=0;i<data->colend;i++) {
        //If the column is float data->columns[i]->floatrows[(int)data->nrows-1] is printed
        if(i<data->colstart) {
            printf("%-10.2f\t", data->columns[i]->floatrows[(int)data->nrows-1]);
        }
        //Else the column is string data->columns[i]->stringrows[(int)data->nrows-1] is printed
        else{
            printf("%-10.10s\t", data->columns[i]->stringrows[(int)data->nrows-1]);
        }
    }

}

//Declaration of method projectDT with DataTable_T pointer parameter
DataTable_t *projectDT(DataTable_t *data){
    //Declaring of temporary string variables str1 and str2
    char str1[SSIZE],str2[SSIZE];
    //Declaring integer parameters
    int x,y,m,n;
    //Declaring variables notvalid to be used in loop
    int notvalid;
    printf("\n");

    //Performing validation on inputs
   do {
            //User inputs 2 strings
           printf("\nInput x rows");
           scanf("%s", str1);
           printf("\nInput y rows");
           scanf("%s", str2);
           notvalid = 1;//Setting notvalid to 1
   //Looping through all the character in the string and checking if they are digits, if they are not notvalid is set to 0
           for(int i=0;i<strlen(str1);i++) {
               if(isdigit(str1[i])==0){
                   notvalid=0;
               }
           }
   //Looping through all the character in the string and checking if they are digits, if they are not notvalid is set to 0
           for(int i=0;i<strlen(str2);i++) {
               if(isdigit(str2[i])==0){
                   notvalid=0;
             }
           }
           //If notvalid==0 then message is displayed
           if(notvalid==0){
               printf("\nRequired to enter positive integers");
           }
           //Else converting the strings into integers
           else {
               x = atoi(str1);
               y = atoi(str2);

                //If y<x not valid is set to 0 and error message is displayed
               if (y < x) {
                   printf("\ny must be greater than x");
                   notvalid = 0;
               }
               //Checking if x is in required range if not notvalid is set to 0
               if (x <= 0 || x > data->nrows) {
                   printf("\nx must be in range %d - %d", 1, data->nrows);
                   notvalid = 0;
               }
               //Checking if y is in required range if not notvalid is set to 0
               if (y <= 0 || y > data->nrows) {
                   printf("\ny must be in range %d - %d", 1, data->nrows);
                   notvalid = 0;
               }
           }
           //Looping if notvalid==0
    }while(notvalid==0);
   //Decrementing both counts since in C index starts at 0
    x--;
    y--;

    do {
        //User inputs 2 strings
        printf("\nInput m columns");
        scanf("%s", str1);
        printf("\nInput n columns");
        scanf("%s", str2);
        notvalid=1;//Setting notvalid to 1
    //Looping through all the character in the string and checking if they are digits, if they are not notvalid is set to 0
        for(int i=0;i<strlen(str1);i++) {
            if(isdigit(str1[i])==0){
                notvalid=0;
            }
        }
    //Looping through all the character in the string and checking if they are digits, if they are not notvalid is set to 0
        for(int i=0;i<strlen(str2);i++) {
            if(isdigit(str2[i])==0){
                notvalid=0;
            }
        }
        //If notvalid==0 then message is displayed
        if(notvalid==0){
            printf("\nRequired to enter positive integers");
        }
        //Else converting the strings into integers
        else {
            m = atoi(str1);
            n = atoi(str2);
            //If n<m not valid is set to 0 and error message is displayed
            if (n < m) {
                printf("\nn must be greater than m");
                notvalid=0;
            }
            //Checking if n is in required range if not notvalid is set to 0
            if (n <= 0 || n > data->colend) {
                printf("\nn must be in range %d - %d", 1, data->colend);
                notvalid = 0;
            }
            //Checking if m is in required range if not notvalid is set to 0
            if (m <= 0 || m > data->colend) {
                printf("\nm must be in range %d - %d", 1, data->colend);
                notvalid = 0;
            }
        }
        //Looping if notvalid==0
    }while(notvalid==0);
    //Decrementing both counts since in C index starts at 0
    m--;
    n--;

    //Calculating the amount of rows and columns the new Datatable will have:
    int tablerows=(y-x)+1;
    int tablecols=0;
    //Declaring and initialising new DataTable_t
    DataTable_t *data2= initDT(1);
    data2->nrows=tablerows;
        data2->colend =(n-m) +1;
    //Resetting tablecols to 0

    tablecols=0;
    //Looping through respective columns in initial DataTable
    for(int i=m;i<=n;i++) {
        //Copying data->labels[i] into data2->labels[tablecols]
        strcpy(data2->labels[tablecols],data->labels[i]);
        //Incrementing tablecols
        tablecols++;
    }
    //Temporary variable check declared and initialised to 0
    int check=0;
    //Resetting tablecols and tablerows
    tablerows=0;
    tablecols=0;
    //Looping through the rows
    for(int j=x;j<=y;j++) {
        //Looping through the columns
        for (int i = m; i <= n; i++) {
            //Copying the relevant cells based on the whether the row is a float or string
            if (i<data->colstart) {//float
                data2->columns[tablecols]->floatrows[tablerows]= data->columns[i]->floatrows[j];
            } else {//String
                if(check==0) {
                    //meta data column start being used to know the first index of the string rows
                    data2->colstart = tablecols;
                    //Setting check to 1 to prevent entering if statement
                    check=1;
                }
                strcpy(data2->columns[tablecols]->stringrows[tablerows], data->columns[i]->stringrows[j]);
            }
            //Incrementing tablecols
            tablecols++;
        }
        //Incrementing tablerows and resetting tablecols
        tablerows++;
        tablecols=0;
    }
    //Returning DataTable_t pointer
    return data2;
}

//Declaration of method mutateDT with DataTable_T pointer parameter
void mutateDT(DataTable_t *data,float (*floatfunction)(float num,int change),void (*stringfunction)(char* string,char strchange,char strreplace)){
    //Declaration of variabls inptcol,notvalid
    int inptcol,notvalid;
    //Declaration of integer variable which will be used to multiply float rows by 7
    int change=7;
    //Declaring of temporary string str1
    char str1[SSIZE];
    //Declaration of characters t and s which will be used to transpose the character t into a in string columns
    char strchange='t',strreplace='a';
    //Displaying options
    printf("\nChoose a column if a string column is chosen 't' will be replaced by 'a' and \nif an integer column is chosen the column will be multiplied by 7\n");
    //User validation for input
    do {
        //User input String
        printf("\nInput column number");
        scanf("%s", str1);
        notvalid=1;
    //Looping through all the character in the string and checking if they are digits, if they are not notvalid is set to 0
        for(int i=0;i<strlen(str1);i++) {
            if(isdigit(str1[i])==0){
                notvalid=0;
            }
        }
        //If notvalid==0 then message is displayed
        if(notvalid==0){
            printf("\nRequired to enter positive integers");
        }
        //Else converting the strings into integers
        else {
            inptcol = atoi(str1);
            //Checking if inptol is in required range if not notvalid is set to 0
            if (inptcol <= 0|| inptcol > data->colend) {
                printf("\ncolumn must be in range %d - %d",1, data->colend);
                notvalid = 0;
            }
        }
        //Looping if notvalid==0
    }while(notvalid==0);
    //Decrementing both counts since in C index starts at 0
    inptcol--;
    //Looping through all the columns
    for(int i=0;i<data->nrows;i++) {
        //If column is string column else column is integer column
        if (inptcol >= 3) {
            //Calling user defined function
            stringfunction(data->columns[inptcol]->stringrows[i],strchange,strreplace);
        } else {//If column is float
            //Calling user defined function
            float temp=data->columns[inptcol]->floatrows[i];
             data->columns[inptcol]->floatrows[i]=floatfunction(temp,change);
        }
    }
}

//User defined functions:
float floatnumbers(float num, int change)
{
    return (float)change*num;
}


void stringinput(char* string,char strchange,char strreplace)
{
    int pos=0;//Position to hold position of string array
    //Checking if tmp has reached end of string
    while(string[pos]!='\0'){
        //If tmp[pos] is 't' then tmp[pos] is changed to 'a'
        if(string[pos]==strchange){
            string[pos]=strreplace;
        }
        //Incrementing position
        pos++;
    }
}