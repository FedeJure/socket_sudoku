#include "row.h"
#include <stdlib.h>
#include <stdio.h>


int row_draw(int size, cell_t* cells[size][size], int row) {
    char values[size];
    for (int i = 0; i < size; i++) {
        if (cells[row][i]->number == 0) values[i] = 32;
        else values[i] = cells[row][i]->number+'0';
    }
    
    printf("U %c | %c | %c U",values[0],values[1],values[2]); 
    printf(" %c | %c | %c U",values[3],values[4],values[5]);
    printf(" %c | %c | %c U\n",values[6],values[7],values[8]);    
    return 0;
}