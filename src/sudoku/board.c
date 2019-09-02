#include "board.h"
#include "row.h"
#include <stdio.h>
#include <stdlib.h>

int board_init(board_t *self, int size, int values[size][size]) {
    self->size = size;
    _board_init_cells(self, size, values);
    printf("Tablero inicializado\n");    
    return 0;
}




int _board_init_cells(board_t* self, int size, int values[size][size]) {
    printf("Creando celdas\n");
    for (int i = 0; i<size; i++) {
        for (int j = 0; j < size; j++) {
            cell_t cell;
            cell.number = values[i][j];
            cell.original_number = values[i][j];
            cell.editable = values[i][j] == 0;
            self->cells[i][j] = cell;  
        }
    }
    return 0;
}

int board_release(board_t* self) {
    printf("Releasing Board\n");
    return 0;
}


int board_draw(board_t* self) {
    _print_separator();
    row_draw(self->size,self->cells,0);
    _print_line();
    row_draw(self->size,self->cells,1);
    _print_line();
    row_draw(self->size,self->cells,2);
    _print_separator();
    row_draw(self->size,self->cells,3);
    _print_line();
    row_draw(self->size,self->cells,4);
    _print_line();
    row_draw(self->size,self->cells,5);
    _print_separator();
    row_draw(self->size,self->cells,6);
    _print_line();
    row_draw(self->size,self->cells,7);
    _print_line();
    row_draw(self->size,self->cells,8);
    _print_separator();
    return 0;
}

void _print_line() {
    printf("U---+---+---U---+---+---U---+---+---U\n");
}

void _print_separator() {
    printf("U===========U===========U===========U\n");
}