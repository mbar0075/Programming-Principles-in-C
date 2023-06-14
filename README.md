# Programming Principles in C

# Author
**Matthias Bartolo 0436103L**

## Preview:
<p align='center'>
  <img src="https://github.com/mbar0075/Programming-Principles-in-C/assets/103250564/968c5e25-4a47-4b46-8eb8-46f37251345f" style="display: block; margin: 0 auto; width: 85%; height: auto;"></br>
  <img src="https://github.com/mbar0075/Programming-Principles-in-C/assets/103250564/3247ab04-1327-452f-b873-dd8e9c180b3a" style="display: block; margin: 0 auto; width: 20%; height: auto;">
  <img src="https://github.com/mbar0075/Programming-Principles-in-C/assets/103250564/2f085390-aaae-44c6-a92f-09dc06591267"  style="display: block; margin: 0 auto; width: 63%; height: auto;">
</p>

## Description of Task:
The project consisted of two main tasks, each focused on implementing different functionalities related to **Array Manipulation** and a **DataTable library**.

### 1. Array Manipulation:
In the first task, the goal was to implement various array-manipulating functions. These functions included initializing an array with user-provided integer values, displaying the array in a specific format, reversing the content of an array, computing the frequency of values in an array, and displaying the frequency pairs. The project required applying programming principles correctly, providing source code explanations, and demonstrating a working solution for each task.
```c
----------------------
| typedef struct {   | 
|     int value;     | 
|     int frequency; | 
| }freq;             | 
----------------------

| int init_array(int array[]);
| void display(int size,int array[]);
| int *reverse(int *arr1,int *arr2 ,int size);
> void frequency(int arr[],freq pairs[]);
| void display_freq(freq pairs[]);
```

### 2. DataTable library:
The second task involved creating a DataTable library. The library aimed to support storing and processing data elements in a spreadsheet-like structure, resembling n-dimensional matrices. The DataTable structure was designed to store data attributes of floating-point numbers and strings. The associated operations included initializing and deinitializing the DataTable structure, loading and exporting data from/to CSV files, displaying the DataTable, and performing projections and mutations on the data. The implementation of the DataTable library required adhering to programming principles, providing API header files, explaining the source code, and developing a comprehensive test driver.

```c
-------------------------
| typedef union{        | 
|     float floatrows;  | 
|     int introws;      | 
|     char *stringrows; | 
| }location;            | 
-------------------------

---------------------------
| typedef struct{         | 
|     location **columns; | 
|     int nrows;          | 
|     char **labels;      | 
|     int *coltype;       | 
|     int ncols;          | 
| }DataTable_t;           | 
---------------------------

| DataTable_t *initDT(int choice , int noofcols,int noofrows);
| void deinitDT(DataTable_t *data);
| void loadDT(DataTable_t *data);
| void exportDT(DataTable_t *data);
| void showDT(DataTable_t *data);
> DataTable_t *projectDT(DataTable_t *data);
| void mutateDT(DataTable_t *data,float (*floatfunction)(float num,int change),int (*intfunction)(int num,int change),void (*stringfunction)(char* string,char | strchange,char strreplace));
| float floatnumbers(float num,int change);
| int intnumbers(int num,int change);
| void stringinput(char* string,char strchange,char strreplace);
```

### 3. Evaluation:
In both tasks, the project emphasized correct application of programming principles, proper validation of user input, and the provision of working solutions. The tasks were completed as part of the project, and the project's focus was to develop and demonstrate the required functionalities.

In addition to developing the array manipulation system and DataTable library, the project provided me with valuable insights into memory management and pointers. As I worked on implementing the functionalities, I gained further knowledge and understanding of how to effectively allocate and deallocate memory, as well as manipulate data using pointers.

Throughout the project, I also made use of tutorials and additional resources to enhance my understanding of the concepts and techniques involved. These tutorials provided valuable guidance and assistance in tackling specific challenges, improving my problem-solving skills and expanding my knowledge base in database management systems.

By engaging with tutorials and leveraging external resources, I was able to deepen my comprehension of the project's subject matter and ensure the successful completion of the assigned tasks. This highlights my proactive approach to learning and my dedication to acquiring a comprehensive understanding of the project's objectives.

Overall, the project not only allowed me to gain practical experience in developing software solutions for array manipulation and DataTable management but also provided an opportunity to further develop my knowledge in memory management and pointers through independent learning and exploration of additional resources.

## Deliverables:
The repository includes :<br />
1. cps1011-tutorials-main - directory which holds various tutorials
2. cps1011-tutorials-submission - directory which holds assignment
 
