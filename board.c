#include "board.h"
#include "row.h"
#include <stdio.h>
#include <stdlib.h>

int board_init(board_t *self, int size, int values[size][size]) {
    _board_init_storage(self, size);
    _board_init_cells(self, size, values);
    printf("Tablero inicializado\n");    
    return 0;
}

int board_release(board_t* self) {
    printf("Releasing Board\n");
    int size = *self->size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            free(self->cells[i][j]);
        }
        free(self->cells[i]);
    }
    free(self->cells);
    free(self->size);
    return 0;
}

int _board_init_storage(board_t* self, int size) {
    int* size_storage = malloc(sizeof(int));
    self->size = size_storage;
    *self->size = size;
    cell_t*** storage_cells = malloc(size * sizeof(cell_t));
    for (int i = 0; i < size; i++) {
        storage_cells[i] = malloc(size * sizeof(cell_t));
        for (int j = 0; j < size; j++) {
            storage_cells[i][j] = malloc(sizeof(cell_t));
        }
        
    }
    self->cells = storage_cells;
    
    return 0;
}

int _board_init_cells(board_t* self, int size, int values[size][size]) {
    printf("Creando celdas\n");  
    for (int i = 0; i<size; i++) {
        for (int j = 0; j < size; j++) {
            self->cells[i][j]->number = values[i][j];
            self->cells[i][j]->original_number = values[i][j];
        }
    }
    return 0;
}

int board_draw(board_t* self) {
    printf("U===========U===========U===========U\n");
    int size = *self->size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %d ",self->cells[i][j]->number);
        }
        printf("\n");
        
    }
    printf("U===========U===========U===========U");
    
    
    return 0;
}
