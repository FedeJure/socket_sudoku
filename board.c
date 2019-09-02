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
            self->cells[i][j]->editable = values[i][j] == 0;
        }
    }
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


int board_draw(board_t* self) {
    _print_separator();
    row_draw(*self->size,self->cells,0);
    _print_line();
    row_draw(*self->size,self->cells,1);
    _print_line();
    row_draw(*self->size,self->cells,2);
    _print_separator();
    row_draw(*self->size,self->cells,3);
    _print_line();
    row_draw(*self->size,self->cells,4);
    _print_line();
    row_draw(*self->size,self->cells,5);
    _print_separator();
    row_draw(*self->size,self->cells,6);
    _print_line();
    row_draw(*self->size,self->cells,7);
    _print_line();
    row_draw(*self->size,self->cells,8);
    _print_separator();
    return 0;
}

void _print_line() {
    printf("U---+---+---U---+---+---U---+---+---U\n");
}

void _print_separator() {
    printf("U===========U===========U===========U\n");
}