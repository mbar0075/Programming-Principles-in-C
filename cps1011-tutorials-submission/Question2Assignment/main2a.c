//Runner file
//Header file used in the program:
#include "functionClass2a.h"

int main() {
//Calling the respective methods from the functionClass.c
// Calling initDT method with choice-0 , since creating a new DataTable from file
    DataTable_t *data=initDT(0);
    loadDT(data);
    showDT(data);
    exportDT(data);
    DataTable_t *data2=projectDT(data);
    showDT(data2);
    deinitDT(data2);
    mutateDT(data,floatnumbers,stringinput);
    showDT(data);
    deinitDT(data);

    return 0;
}
