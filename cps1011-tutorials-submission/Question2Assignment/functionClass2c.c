//functionClass file which includes methods to be used by runner file
//Libraries used in the program:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Header file used in the program
#include "functionClass2c.h"


//Declaration of method initDT with interger parameters choice,noofcols and noofrows
DataTable_t *initDT(int choice , int noofcols,int noofrows) {
    //Declaration of DataTable_t pointer
    DataTable_t *data;

    //If choice is 0 , then the DataTable is initialised from a file
    if(choice==0) {
        //Creating size in heap for DataTable_t
        data = (DataTable_t *) malloc(sizeof(DataTable_t));
        //If no sufficient memory is found error message is displayed
        if (data == NULL) {
            printf("There wasn't sufficient memory to complete this operation");
            exit(1);
        }

        //Declaring file pointer and opening file in read mode
        FILE *fptr;
        if ((fptr = fopen("Testing2.csv", "r")) == NULL) {
            //If file is not found an Error message is presented
            printf("Error file not found");
        } else {
            //Declaration of variables tmp1,tmp2,prevchar and count
            char tmp1, tmp2, prevchar;
            int count = 1;
            //Do while loop being used to find the number of populated columns
            do {
                //tmp1 is used to hold the current character whilst prevchar is used to hold hte previous character
                prevchar = tmp1;
                //tmp1 used to hold the cureent char read from file
                tmp1 = (char) fgetc(fptr);
                //If a , is found the counter is incremented
                if (tmp1 == ',' && (tmp1 == ',' && prevchar != '\\')) {
                    count++;
                }
                //If a \n is found , the program breaks
                if (tmp1 == '\n') {
                    break;
                }
            } while (tmp1 != '\0');
            //Storing the count in data->ncols
            data->ncols = count;

            //To rewind the file pointer
            rewind(fptr);
            //Re-initialising count to 0
            count = 0;
            //Do while loop being used to find the number of populated rows
            do {
                //tmp2 used to hold the cureent char read from file
                tmp2 = (char) fgetc(fptr);
                //If a \n is found, count is incremented
                if (tmp2 == '\n') {
                    count++;
                }
                //Looping until end of file is reached
            } while (tmp2 != EOF);
            //Storing the count in data->nrows
            data->nrows = count;


            //To rewind the file pointer
            rewind(fptr);

            //The code to get the datatypes for the columns
            //Declaration of currentchar,previouschar and noofChars
            char currentchar, previouschar;
            int noofChars = 0;
            //Declaring string line and allocating memory for it
            char *line = (char *) malloc(sizeof(char));
            //If no sufficient memory is found error message is displayed
            if (line == NULL) {
                printf("There wasn't sufficient memory to complete this operation");
                exit(1);
            }
            do {//Looping through the first line
                //currentchar used to hold the cureent char read from file
                currentchar = (char) fgetc(fptr);
                //If a , is found the noofChars is incremented
                if (currentchar == ',' && previouschar != '\\') {
                    line[noofChars] = ',';
                    noofChars++;
                } else {
                    //Setting previoushchar to be currentchar
                    previouschar = currentchar;
                    //storing currentchar in index noofChars in line
                    line[noofChars] = currentchar;
                    //If statement when first character is entered in the line
                    if (noofChars == 0) {
                        //storing currentchar in index noofChars in line
                        line[noofChars] = currentchar;
                        //Incrementing noofChars
                        noofChars++;
                        //Setting line[noofChars] to null
                        line[noofChars] = '\0';
                    } else {
                        //Reallocating memory for line
                        line = (char *) realloc(line, noofChars + 2);
                        //If no sufficient memory is found error message is displayed
                        if (line == NULL) {
                            printf("There wasn't sufficient memory to complete this operation");
                            exit(1);
                        }
                        //printf("\n%c",line[noofChars]);
                        //storing currentchar in index noofChars in line
                        line[noofChars] = currentchar;
                        //Incrementing noofChars
                        noofChars++;
                        //Setting line[noofChars] to null
                        line[noofChars] = '\0';

                    }
                }
                //Looping until a \n appears
            } while (currentchar != '\n');

            //Allocating memory for data->coltype
            data->coltype = (int *) malloc((data->ncols) * sizeof(int));
            //If no sufficient memory is found error message is displayed
            if (data->coltype == NULL) {
                printf("There wasn't sufficient memory to complete this operation");
                exit(1);
            }
            //Setting currentchar to null
            currentchar = '\0';
            //Declaring of counts digits,chars,points and others
            //Declaring position as index
            int pos = 0;
            int digits = 0, chars = 0, points = 0, others = 0;
            //Looping through all the characters in string line
            for (int i = 0; i < strlen(line) + 1; i++) {
                //Setting previouschar to hold currentchar
                previouschar = currentchar;
                //Setting previouschar to hold line[i]
                currentchar = line[i];
                //If currentchar is a ',' or '\0' and previouschar !=\ and currentchar =, ,then it enters the if statement
                if (!((currentchar != ',' && (currentchar != '\0')) || (currentchar == ',' && previouschar == '\\'))) {
                    //If conditions for the counters to be float
                    if (points == 1 && digits > 0 && chars == 0) {//when Float let the signal bit be 1
                        //Setting data->coltype[pos] to 1
                        data->coltype[pos] = 1;
                        //Incrementing index pos
                        pos++;
                    } else if (digits > 0 && points == 0 && chars == 0) {//when Integer let the signal bit be 2
                        // Setting data->coltype[pos] to 2
                        data->coltype[pos] = 2;
                        //Incrementing index pos
                        pos++;
                    } else {//when String let the signal bit be 4
                        //Setting data->coltype[pos] to 4
                        data->coltype[pos] = 4;
                        //Incrementing index pos
                        pos++;
                    }
                    //Resetting all counters to 0
                    digits = 0, chars = 0, points = 0, others = 0;
                } else {
                    //If currentchar is a letter , chars is incremented
                    if (isalpha(currentchar) != 0) {
                        chars++;
                        //If currentchar is a digit , digits is incremented
                    } else if (isdigit(currentchar) != 0) {
                        digits++;
                        //If currentchar is a ., points is incremented
                    } else if (currentchar == '.') {
                        points++;
                        //Else others is incremented
                    } else {
                        others++;
                    }
                }
            }
            //Freeing the line
            free(line);
            //Closing the file
            fclose(fptr);

            //Allocating size for all column rows
            data->columns = (location **) malloc((data->ncols) * sizeof(location *));//number of rows
            //If no sufficient memory is found error message is displayed
            if (data->columns == NULL) {
                printf("There wasn't sufficient memory to complete this operation");
                exit(1);
            }
            //Allocating size for all column columns
            for (int i = 0; i < data->ncols; i++) {
                //Allocating more memory than required to be safe
                data->columns[i] = (location *) malloc((2*data->nrows+1) * sizeof(location));//number of columns
                //If no sufficient memory is found error message is displayed
                if (data->columns[i]== NULL) {
                    printf("There wasn't sufficient memory to complete this operation");
                    exit(1);
                }
            }

            //Allocating size for column titles:
            data->labels = (char **) malloc((data->ncols) * sizeof(char *));
            //If no sufficient memory is found error message is displayed
            if (data->labels == NULL) {
                printf("There wasn't sufficient memory to complete this operation");
                exit(1);
            }
            //Declaring string tmp and char input variabls
            char *tmp;
            char input;
            //Resetting noofChars to 0
            noofChars = 0;
            //Utilising a for loop for the user to input labels and storing the user input in data->labels array
            for (int i = 0; i < data->ncols; i++) {
                printf("\nEnter label %d", i + 1);

                do {
                    //Getting character from user
                    input = getchar();
                    //If input !=\n enter if statement
                    if (input != '\n') {
                        //If statement when first character is entered
                        if (noofChars == 0) {
                            //Allocating memory for tmp
                            tmp = (char *) malloc(sizeof(char));
                            //If no sufficient memory is found error message is displayed
                            if (tmp == NULL) {
                                printf("There wasn't sufficient memory to complete this operation");
                                exit(1);
                            }
                            //Adding the input to the string tmp
                            tmp[noofChars] = input;
                            //Incrementing noofChars
                            noofChars++;
                            //Setting tmp[noofChars] to null
                            tmp[noofChars] = '\0';
                        } else {
                            //Reallocating memory for tmp
                            tmp = (char *) realloc(tmp, noofChars + 1);
                            //If no sufficient memory is found error message is displayed
                            if (tmp == NULL) {
                                printf("There wasn't sufficient memory to complete this operation");
                                exit(1);
                            }
                            //Adding the input to the string tmp
                            tmp[noofChars] = input;
                            //Incrementing noofChars
                            noofChars++;
                            //Setting tmp[noofChars] to null
                            tmp[noofChars] = '\0';
                        }
                    }
                    //Looping until input !=\n
                } while (input != '\n');
                //Allocating memory for data->labels[i]
                data->labels[i] = (char *) malloc(noofChars * sizeof(char));
                //If no sufficient memory is found error message is displayed
                if (data->labels[i] == NULL) {
                    printf("There wasn't sufficient memory to complete this operation");
                    exit(1);
                }
                //Utilising the strcpy to copy the contents of tmp into data->labels[i]
                strcpy(data->labels[i], tmp);
                //Freeing tmp
                free(tmp);
                //Resetting noofChars to 0
                noofChars = 0;
            }
        }

    }
        //If choice is 1 , then the DataTable is initialised from an already existing Datatable to have specific rows and columns
    else if(choice==1){
        //Creating size in heap for DataTable_t
        data=(DataTable_t*)malloc(sizeof(DataTable_t));
        //If no sufficient memory is found error message is displayed
        if (data == NULL) {
            printf("There wasn't sufficient memory to complete this operation");
            exit(1);
        }
        //Assigning the passed parameters to number of columns and number of rows of the Datatable
        data->ncols=noofcols;
        data->nrows=noofrows;
        //Allocating memory for data->labels
        //Allocating more memory than required to be safe
        data->labels= (char **) malloc((2*data->ncols+1) * sizeof(char *));
        //If no sufficient memory is found error message is displayed
        if (data->labels == NULL) {
            printf("There wasn't sufficient memory to complete this operation");
            exit(1);
        }
        //Allocating memory for data->coltype
        //Allocating more memory than required to be safe
        data->coltype = (int *) malloc((2*data->ncols+1) * sizeof(int));
        //If no sufficient memory is found error message is displayed
        if (data->coltype == NULL) {
            printf("There wasn't sufficient memory to complete this operation");
            exit(1);
        }

        //Allocating size for all column rows
        //Allocating more memory than required to be safe
        data->columns = (location **) malloc((2*data->ncols+1) * sizeof(location *));//number of rows
        //If no sufficient memory is found error message is displayed
        if (data->columns == NULL) {
            printf("There wasn't sufficient memory to complete this operation");
            exit(1);
        }
        //Allocating size for all column columns
        for (int i = 0; i < data->ncols; i++) {
            //Allocating more memory than required to be safe
            data->columns[i] = (location *) malloc((2*data->nrows+1) * sizeof(location));//number of columns
            //If no sufficient memory is found error message is displayed
            if (data->columns[i] == NULL) {
                printf("There wasn't sufficient memory to complete this operation");
                exit(1);
            }
        }

    }
    //Returning DataTable_t pointer
    return data;
}

//Declaration of method deinitDT with DataTable_T pointer parameter
void deinitDT(DataTable_t *data){

    //Looping through all the columns
    for( int i=0;i<data->ncols;i++){
        //Freeing columns[i]and labels[i] from memory
        free(data->columns[i]);
        free(data->labels[i]);
    }
    //Freeing coltype,labels and columns from memory
    free(data->coltype);
    free(data->labels);
    free(data->columns);
    //Freeing the DataTable_t from memory
    free(data);

}

//Declaration of method loadDT with DataTable_T pointer parameter
void loadDT(DataTable_t *data){
    //Declaration of file pointer fptr
    FILE *fptr;
    //Opening the file in reading mode
    if((fptr=fopen("Testing2.csv","r"))==NULL)
    {
        //If file is not found an Error message is presented
        printf("Error file not found");
    }
    else {
        //To find the maximum number of characters in a line
        //Declaring variables linecount , max and filechar
        int linecount=0,max=0;
        char filechar;
        do{//Looping through the whole file
            //Getting a character from the file and storing it in filechar
            filechar=fgetc(fptr);
            //If filechar =='\n' or EOF, enter if statement
            if(filechar=='\n'||filechar==EOF){
                //Finding the max number of characters in a line
                if(max<linecount){
                    max=linecount;
                }
                //Resetting linecount
                linecount=0;
            }
                //Incrementing linecount
            else{
                linecount++;
            }
            //Looping until end of file is reached
        }while(filechar!=EOF);

        //Rewinding file pointer
        rewind(fptr);
        //Declaring of variable tmp and allocating memory for it to act as a temporary string
        char *tmp= (char *) malloc((max+1)*sizeof(char));
        //If no sufficient memory is found error message is displayed
        if (tmp == NULL) {
            printf("There wasn't sufficient memory to complete this operation");
            exit(1);
        }
        //Declaring variable rows
        int rows = 0;
        //Reading one line from file
        while (fgets(tmp, max, fptr) != NULL) {
            //Declaring of variable line to hold the current line read from file
            char *line2;
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
            line2 = strtok(tmp, ",");
            //Declaring variable cols to act as a counter for the columns in the DataTable_t
            int cols = 0;

            if(rows<=data->nrows) {
                //While loop being used to check if end of line was not reached
                while (line2 != NULL) {
                    //If data->coltype[cols]==1 then column is float
                    if (data->coltype[cols] == 1) {
                        //Using atof to turn string into float and storing it in data->columns[cols][rows].floatrows
                        data->columns[cols][rows].floatrows = atof(line2);
                        //If data->coltype[cols]==2 then column is integer
                    } else if (data->coltype[cols] == 2) {
                        //Using atof to turn string into int and storing it in data->columns[cols][rows].introws
                        data->columns[cols][rows].introws=atoi(line2);
                        //If data->coltype[cols]==4 then column is String
                    } else if (data->coltype[cols] == 4) {
                        //Resetting position to 0
                        pos = 0;
                        //While loop used to check if end of string is reached
                        while (line2[pos] != '\0') {
                            //If character is \. then we transpose it to ,
                            if (line2[pos] == '\\' && line2[pos + 1] == '.') {
                                line2[pos] = ',';
                                line2[pos + 1] = ' ';
                            }
                            //Incrementing position
                            pos++;
                        }

                        //Allocating sufficient memory for data->columns[cols][rows].stringrows
                        data->columns[cols][rows].stringrows = (char *) malloc((strlen(line2)) * sizeof(char));
                        //If no sufficient memory is found error message is displayed
                        if (data->columns[cols][rows].stringrows == NULL) {
                            printf("There wasn't sufficient memory to complete this operation");
                            exit(1);
                        }
                        //Copying the contents of line2 to data->columns[cols][rows].stringrows
                        strcpy(data->columns[cols][rows].stringrows, line2);

                    }



                    //Incrementing cols
                    cols++;
                    //Updating the location of the next token
                    line2 = strtok(NULL, ",");
                }
                //Incrementing rows and resetting cols
                rows++;
                cols = 0;
            }
        }
        //Freeing tmp from memory
        free(tmp);
        //Closing the file
        fclose(fptr);

    }
}

//Declaration of method exportDT with DataTable_T pointer parameter
void exportDT(DataTable_t *data){
    //Declaration of file pointer fptr
    FILE *fptr;
    //Opening the file in writing mode
    fptr=fopen("OutputFile.csv","w");
    //Opening the file in reading mode
    FILE *fptr2;
    if((fptr2=fopen("Testing2.csv","r"))==NULL)
    {
        //If file is not found an Error message is presented
        printf("Error file not found to complete this action");
    }
    else {
        //To find the maximum number of characters in a line
        //Declaring variables linecount , max and filechar
        int linecount = 0, max = 0;
        char filechar;
        do {//Looping through the whole file
            //Getting a character from the file and storing it in filechar
            filechar = fgetc(fptr2);
            //If filechar =='\n' or EOF, enter if statement
            if (filechar == '\n' || filechar == EOF) {
                //Finding the max number of characters in a line
                if (max < linecount) {
                    max = linecount;
                }
                //Resetting linecount
                linecount = 0;
            } else {
                //Incrementing linecount
                linecount++;
            }
            //Looping until end of file is reached
        } while (filechar != EOF);


        //Looping through all the populated rows
        for (int i = 0; i < data->nrows; i++) {
            //Allocating sufficient memory for temp and resetting all values to '\0' via memset
            //Allocating more memory than required to be safe
            char *temp= (char *) malloc((max+10)*sizeof(char));
            //If no sufficient memory is found error message is displayed
            if (temp == NULL) {
                printf("There wasn't sufficient memory to complete this operation");
                exit(1);
            }
            memset(temp, '\0', (max+10)*sizeof(char));
            //Looping through the float columns
            for (int j = 0; j <data->ncols ; j++) {
                //If data->coltype[cols]==1 then column is float
                if(data->coltype[j]==1) {
                    //Declaring variable max digits
                    int maxdigits=0;
                    //Storing data->columns[j][i].floatrows in temp2
                    float temp2=data->columns[j][i].floatrows;
                    //Finding the number of digits in temp2
                    while(temp2>0.001){
                        temp2 = temp2 / 10;
                        maxdigits++;
                    }
                    //Allocation of sufficient memory for text
                    //Allocating more memory than required to be safe
                    char *text= (char *) malloc((maxdigits+10)*sizeof(char));
                    //If no sufficient memory is found error message is displayed
                    if (text == NULL) {
                        printf("There wasn't sufficient memory to complete this operation");
                        exit(1);
                    }
                    //Transforming the float into string using gcvt
                    gcvt( data->columns[j][i].floatrows, maxdigits, text);
                    //Appending the float to the string text
                    strcat(temp, text);
                    //If statement being used to append a , to the string temp to signify end of entity, besides when final column is reached
                    if (j != data->ncols - 1) {
                        strcat(temp, ",");
                    }
                    //Freeing text
                    free(text);
                    text=NULL;
                }
                    //If data->coltype[cols]==2 then column is integer
                else if(data->coltype[j]==2){
                    //Declaring variable max digits
                    int maxdigits=0;
                    //Storing data->columns[j][i].introws in temp2
                    int temp2=data->columns[j][i].introws;
                    //Finding the number of digits in temp2
                    while(temp2>0){
                        temp2 = temp2 / 10;
                        maxdigits++;
                    }
                    //Allocation of sufficient memory for text
                    //Allocating more memory than required to be safe
                    char *text= (char *) malloc((maxdigits+10)*sizeof(char));
                    //If no sufficient memory is found error message is displayed
                    if (text == NULL) {
                        printf("There wasn't sufficient memory to complete this operation");
                        exit(1);
                    }
                    //Transforming the float into string using itoa
                    itoa( data->columns[j][i].introws,  text,10);//10 be the base decimal
                    //Appending the float to the string text
                    strcat(temp, text);
                    //If statement being used to append a , to the string temp to signify end of entity, besides when final column is reached
                    if (j != data->ncols - 1) {
                        strcat(temp, ",");
                    }
                    //Freeing text
                    free(text);
                    text=NULL;
                }
                    //If data->coltype[cols]==4 then column is string
                else if(data->coltype[j]==4){//String
                    //Allocating sufficient memory for words and setting it to hold data->columns[j][i].stringrows
                    //Allocating more memory than required to be safe
                    char *words= (char *) malloc(sizeof(data->columns[j][i].stringrows)+10);
                    //If no sufficient memory is found error message is displayed
                    if (words == NULL) {
                        printf("There wasn't sufficient memory to complete this operation");
                        exit(1);
                    }
                    strcpy(words,data->columns[j][i].stringrows);
                    //Declaring variable to hold the position of string tmp
                    int pos = 0;
                    //While loop used to check if end of string is reached
                    while (words[pos] != '\0') {
                        //If character is , then we transpose it to \,
                        if (words[pos] == ',' && words[pos +1] == ' ') {
                            words[pos] = '\\';
                            words[pos + 1] = ',';
                            pos++;
                        }
                        //Incrementing position
                        pos++;
                    }
                    //Appending the words to the string temp
                    strcat(temp, words);
                    //If statement being used to append a , to the string temp to signify end of entity, besides when final column is reached
                    if (j != data->ncols - 1) {
                        strcat(temp, ",");
                    }
                    //Freeing words
                    free(words);
                    words=NULL;

                }

            }

            //Printing to file the string temp
            fprintf(fptr, "%s", temp);
            //Printing \n to file to indicate a new row in case there wasn't
            if(temp[strlen(temp)-1]!='\n'){
                //Printing to file the string temp
                fprintf(fptr, "%s", "\n");
            }
            //Freeing temp
            free(temp);
            temp=NULL;
;
        }
    }
    //Closing the files
    fclose(fptr);
    fclose(fptr2);
}

//Declaration of method showDT with DataTable_T pointer parameter
void showDT(DataTable_t *data){
    printf("\n");
    //For loop being used to show the labels
    printf("\t");
    for(int i=0;i<data->ncols;i++) {
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
        //For loop being used to display the columns
        for(int i=0;i<data->ncols;i++) {
            //If data->coltype[cols]==1 then column is float
            if(data->coltype[i]==1) {
                if(j==temp){
                    printf(".................");
                }
                else {
                    printf("%-10.2f\t", data->columns[i][j].floatrows);
                }
            }
                //If data->coltype[cols]==2 then column is integer
            else if(data->coltype[i]==2) {
                if(j==temp){
                    printf(".................");
                }
                else {
                    printf("%-10.2d\t", data->columns[i][j].introws);
                }
            }
                //If data->coltype[cols]==4 then column is string
            else if(data->coltype[i]==4) {
                if(j==temp){
                    printf(".................");
                }
                else {
                    printf("%-10.10s\t", data->columns[i][j].stringrows);
                }
            }
        }


        printf("\n");
    }
    //Printing the number of the last row
    printf("%d\t",(int)data->nrows);
    //Looping through all the columns in the last row
    for(int i=0;i<data->ncols;i++) {
        //If the column is float contents of data->columns[i][data->nrows-1].floatrows is printed
        if(data->coltype[i]==1) {
            printf("%-10.2f\t", data->columns[i][data->nrows-1].floatrows);
        }
            //If the column is integer contents of data->columns[i][data->nrows-1].introws is printed
        else if(data->coltype[i]==2){
            printf("%-10.2d\t", data->columns[i][data->nrows-1].introws);
        }
            //Else the column is string contents of data->columns[i][data->nrows-1].stringrows is printed
        else if(data->coltype[i]==4){
            printf("%-10.10s\t", data->columns[i][data->nrows-1].stringrows);
        }
    }

}

//Declaration of method projectDT with DataTable_T pointer parameter
DataTable_t *projectDT(DataTable_t *data){

    //To find the size of the largest row number
    int maxdigits=0,temp=data->nrows;
    while(temp>0){
        temp = temp / 10;
        maxdigits++;
    }
    //Allocating sufficient memory for str1 and str2, allocating more memory than required to be safe
    char *str1= (char *) malloc((maxdigits+7)* sizeof(char));
    //If no sufficient memory is found error message is displayed
    if (str1 == NULL) {
        printf("There wasn't sufficient memory to complete this operation");
        exit(1);
    }
    char *str2= (char *) malloc((maxdigits+7)* sizeof(char));
    //If no sufficient memory is found error message is displayed
    if (str2 == NULL) {
        printf("There wasn't sufficient memory to complete this operation");
        exit(1);
    }

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

    //To find the size of the largest column number
    maxdigits=0,temp=data->ncols;
    while(temp>0){
        temp = temp / 10;
        maxdigits++;
    }
    //Allocating memory for str3 and str4, allocating more memory than required to be safe
    char *str3= (char *) malloc((maxdigits+10)*sizeof(char));
    //If no sufficient memory is found error message is displayed
    if (str3 == NULL) {
        printf("There wasn't sufficient memory to complete this operation");
        exit(1);
    }
    char *str4= (char *) malloc((maxdigits+10)*sizeof(char));
    //If no sufficient memory is found error message is displayed
    if (str4 == NULL) {
        printf("There wasn't sufficient memory to complete this operation");
        exit(1);
    }

    do {
        //User inputs 2 strings
        printf("\nInput m columns");
        scanf("%s", str3);
        printf("\nInput n columns");
        scanf("%s", str4);
        notvalid=1;//Setting notvalid to 1
        //Looping through all the character in the string and checking if they are digits, if they are not notvalid is set to 0
        for(int i=0;i<strlen(str3);i++) {
            if(isdigit(str3[i])==0){
                notvalid=0;
            }
        }
        //Looping through all the character in the string and checking if they are digits, if they are not notvalid is set to 0
        for(int i=0;i<strlen(str4);i++) {
            if(isdigit(str4[i])==0){
                notvalid=0;
            }
        }
        //If notvalid==0 then message is displayed
        if(notvalid==0){
            printf("\nRequired to enter positive integers");
        }
            //Else converting the strings into integers
        else {
            m = atoi(str3);
            n = atoi(str4);
            //If n<m not valid is set to 0 and error message is displayed
            if (n < m) {
                printf("\nn must be greater than m");
                notvalid=0;
            }
            //Checking if n is in required range if not notvalid is set to 0
            if (n <= 0 || n > data->ncols) {
                printf("\nn must be in range %d - %d", 1, data->ncols);
                notvalid = 0;
            }
            //Checking if m is in required range if not notvalid is set to 0
            if (m <= 0 || m > data->ncols) {
                printf("\nm must be in range %d - %d", 1, data->ncols);
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
    int tablecols=(n-m)+1;
    //Calling initDT method and passing choice as 1 since a new DataTable is created based on DataTable data
    //and respective tablecols and tablerows as parameters
    DataTable_t *data2= initDT(1,tablecols,tablerows);
    //Resetting tablecols to 0
    tablecols=0;

    //Looping through respective columns in initial DataTable
    for(int i=m;i<=n;i++) {
        //Allocating memory to label[i]
        data2->labels[tablecols] = (char *) malloc(sizeof(data->labels[i])+1);
        //If no sufficient memory is found error message is displayed
        if (data->labels[tablecols] == NULL) {
            printf("There wasn't sufficient memory to complete this operation");
            exit(1);
        }
        //Copying data->labels[i] into data2->labels[tablecols]
        strcpy(data2->labels[tablecols],data->labels[i]);
        //Setting  data2->coltype[tablecols] to data->coltype[i]
        data2->coltype[tablecols]=data->coltype[i];
        //Incrementing tablecols
        tablecols++;
    }

    //Resetting tablecols and tablerows
    tablerows=0;
    tablecols=0;
    //Looping through the rows
    for(int j=x;j<=y;j++) {
        //Looping through the columns
        for (int i = m; i <= n; i++) {
            //Copying the relevant cells based on the whether the row is a float,integer or string
            if (data2->coltype[tablecols] == 1) {//float
                data2->columns[tablecols][tablerows].floatrows = data->columns[i][j].floatrows;
            } else if (data2->coltype[tablecols] == 2) {//Integer
                data2->columns[tablecols][tablerows].introws = data->columns[i][j].introws;
            } else if (data2->coltype[tablecols] == 4) {//String
                data2->columns[tablecols][tablerows].stringrows=(char*)malloc(sizeof(data->columns[i][j].stringrows+1));
                //If no sufficient memory is found error message is displayed
                if (data2->columns[tablecols][tablerows].stringrows == NULL) {
                    printf("There wasn't sufficient memory to complete this operation");
                    exit(1);
                }
                strcpy(data2->columns[tablecols][tablerows].stringrows , data->columns[i][j].stringrows);
            }
            //Incrementing tablecols
            tablecols++;
        }
        //Incrementing tablerows and resetting tablecols
        tablerows++;
        tablecols=0;
    }

    //Freeing relevant strings
    free(str1);
    str1=NULL;
    free(str2);
    str2=NULL;
    free(str3);
    str3=NULL;
    free(str4);
    str4=NULL;

    //Returning new Datatable pointer
    return data2;
}

//Declaration of method mutateDT with DataTable_T pointer and user defined functions as parameters
void mutateDT(DataTable_t *data,float (*floatfunction)(float num,int change),int (*intfunction)(int num,int change),void (*stringfunction)(char* string,char strchange,char strreplace)){
    //Declaration of variables inptcol,notvalid
    int inptcol,notvalid;
    //Declaration of integer variable which will be used to multiply float rows and int rows by 7
    int change=7;
    //To find the size of the largest row number
    int maxdigits=0,temp=data->ncols;
    while(temp>0){
        temp = temp / 10;
        maxdigits++;
    }
    //Declaring and allocating memory for str5, allocating more memory than required to be safe
    char *str5= (char *) malloc((maxdigits+10)*sizeof(char));
    //If no sufficient memory is found error message is displayed
    if (str5 == NULL) {
        printf("There wasn't sufficient memory to complete this operation");
        exit(1);
    }
    //Declaration of character variables which will be used to transpose the character t into a in string columns
    char strchange='t',strreplace='a';

    //Displaying options
    printf("\nChoose a column if a string column is chosen 't' will be replaced by 'a' and \nif an integer or float column is chosen the column will be multiplied by 7\n");
    //User validation for input
    do {
        //User input String
        printf("\nInput column number");
        scanf("%s", str5);
        notvalid=1;
        //Looping through all the character in the string and checking if they are digits, if they are not notvalid is set to 0
        for(int i=0;i<strlen(str5);i++) {
            if(isdigit(str5[i])==0){
                notvalid=0;
            }
        }
        //If notvalid==0 then message is displayed
        if(notvalid==0){
            printf("\nRequired to enter positive integers");
        }
            //Else converting the strings into integers
        else {
            inptcol = atoi(str5);
            //Checking if inptol is in required range if not notvalid is set to 0
            if (inptcol <= 0 || inptcol > data->ncols) {
                printf("\ncolumn must be in range %d - %d", 1,data->ncols);
                notvalid = 0;
            }
        }
        //Looping if notvalid==0
    }while(notvalid==0);
    //Decrementing both counts since in C index starts at 0
    inptcol--;
    //Looping through all the columns
    for(int i=0;i<data->nrows;i++) {
        //Based on column type respective if statement is chosen
        if(data->coltype[inptcol]==1) {//Float
            //user defined function
            data->columns[inptcol][i].floatrows=floatfunction(data->columns[inptcol][i].floatrows,change);
        }
        else if(data->coltype[inptcol]==2) {//Integer
            //user defined function
            data->columns[inptcol][i].introws=intfunction(data->columns[inptcol][i].introws,change);
        }
        else if(data->coltype[inptcol]==4) {//String

            //user defined function
            stringfunction(data->columns[inptcol][i].stringrows,strchange,strreplace);

        }
    }
    //Freeing str5
    free(str5);
    str5=NULL;

}

//User defined functions:
float floatnumbers(float num, int change)
{
    return (float)change*num;
}

int intnumbers(int num, int change)
{
    return change*num;
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

