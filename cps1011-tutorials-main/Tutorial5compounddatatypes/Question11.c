#include <stdio.h>
#include <string.h>
#define NLEN 30
#define SIZE 2

typedef char string_t[NLEN];

//Creating structure of type employee
typedef struct {
    string_t name;
    string_t surname;
    int ID;
    float salary;
} employee_t;

void initialise(employee_t employee[]);
void print(employee_t employee[]);
void sortID(int *pntr[],employee_t employee[]);
void sortS(char *pntr[],employee_t employee[]);

int main(void)
{
    employee_t employee[SIZE];
    initialise(employee);

    print(employee);

    printf("\n\nSorting Employee by Surname:\n");
    //Creating pointer for surnames
    char *pntr[SIZE];
    //Initialising pointer for surname
    for(int i=0;i<SIZE;i++) {
        pntr[i] = employee[i].surname;
    }
    sortS(pntr,employee);//Sort by surname
    print(employee);

    printf("\n\nSorting Employee by ID:\n");
    //Creating pointer for id
    int *pntrI[SIZE];
    //Initialising pointer for id
    for(int i=0;i<SIZE;i++) {
        pntrI[i] =&employee[i].ID;
    }
    sortID(pntrI,employee);//Sort by ID
    print(employee);

    return 0;
}

void initialise(employee_t employee[]){
    //Initialisation
    for(int i=0;i<SIZE;i++){
        printf("Enter name %d\n",i+1);
        scanf("%s",employee[i].name);
        printf("Enter surname %d\n",i+1);
        scanf("%s",employee[i].surname);
        printf("Enter id %d\n",i+1);
        scanf("%d",&employee[i].ID);
        printf("Enter salary %d\n",i+1);
        scanf("%f",&employee[i].salary);
    }
}

//Method to Print
void print(employee_t employee[]){
    for(int i=0;i<SIZE;i++){
        printf("%s  %s  %d  %.2f\n",employee[i].name,employee[i].surname,employee[i].ID,employee[i].salary);
    }
}

//Method Sort by Surname
void sortS(char *pntr[], employee_t employee[])
{
    employee_t temp;
    int top, seek;
    for (top = 0; top < SIZE-1; top++)
    for (seek = top + 1; seek < SIZE; seek++)
        if (strcasecmp(pntr[top],pntr[seek]) > 0)
        {
            temp = employee[top];
            employee[top] = employee[seek];
            employee[seek] = temp;
        }
}

//Method Sort by ID
void sortID(int *pntr[], employee_t employee[])
{
    employee_t temp;
    int top, seek;
    for (top = 0; top < SIZE-1; top++)
        for (seek = top + 1; seek < SIZE; seek++)
            if (pntr[top]>pntr[seek])
            {
                temp = employee[top];
                employee[top] = employee[seek];
                employee[seek] = temp;
            }
}