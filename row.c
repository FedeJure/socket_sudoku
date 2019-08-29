#include "row.h"
#include <stdlib.h>
#include <stdio.h>

int row_init(row_t* self, cell_t* cells, int size) {
    self->size = size;
    self->cells = malloc(sizeof(cell_t*));
    
    for (int i = 0; i < size; i++) {
        self->cells[i] = &cells[i];
    }
    return 0;
}

int row_release(row_t* self) {
    free(self->cells);
    
    return 0;
}

int row_draw(row_t* self) {
    printf("Dibujando fila\n");
    return 0;
}
