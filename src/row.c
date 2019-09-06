#include "row.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int row_draw(int size, cell_t cells[size][size], int row, char* buffer) {
    char values[size];
    for (int i = 0; i < size; i++) {
        if (cells[row][i].number == 0) values[i] = 32;
        else values[i] = cells[row][i].number+'0';
    }
    char* aux = NULL;
    char* format = "U %c | %c | %c U";
    sprintf(aux, format, values[0],values[1],values[2]);
    printf(">%s", aux);
    strcat(buffer, aux);

    sprintf(aux, format, values[3],values[4],values[5]);
    strcat(buffer, aux);

    sprintf(aux, format, values[6],values[7],values[8]);

    strcat(buffer, aux);

    strcat(buffer, "\n");    
    return 0;
}