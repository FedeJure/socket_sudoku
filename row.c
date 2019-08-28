#include "row.h"
#include <stdlib.h>
#include <stdio.h>

int row_init(row_t* self, int values[], int size) {
    self->size = size;
    self->cells = malloc(size * sizeof(cell_t));
    
    for (int i = 0; i < size; i++) {
        int value = values[i];
        cell_t* cell = &self->cells[i];
        cell->original_number=value;
        cell->number = value;
    }
    return 0;
}

int row_release(row_t* self) {
    for (int i = 0; i < 9; i++) {
        free(self->cells);
    }
    
    return 0;
}

int row_draw(row_t* self) {
    printf("Dibujando fila\n");
    return 0;
}
