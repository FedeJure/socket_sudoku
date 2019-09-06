#include "board.h"
#include "row.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            self->cells[i][j] = cell; 
            self->cells[i][j].number = values[i][j];
            self->cells[i][j].original_number = values[i][j];
            self->cells[i][j].editable = values[i][j] == 0 ? 1 : 0;
        }
    }
    return 0;
}

int board_release(board_t* self) {
    printf("Releasing Board\n");
    return 0;
}


int board_draw(board_t* self, char* buffer) {
    _board_draw_separator(buffer);
    row_draw(self->size,self->cells,0, buffer);
    _board_draw_line(buffer);
    row_draw(self->size,self->cells,1, buffer);
    _board_draw_line(buffer);
    row_draw(self->size,self->cells,2, buffer);
    _board_draw_separator(buffer);
    row_draw(self->size,self->cells,3, buffer);
    _board_draw_line(buffer);
    row_draw(self->size,self->cells,4, buffer);
    _board_draw_line(buffer);
    row_draw(self->size,self->cells,5, buffer);
    _board_draw_separator(buffer);
    row_draw(self->size,self->cells,6, buffer);
    _board_draw_line(buffer);
    row_draw(self->size,self->cells,7, buffer);
    _board_draw_line(buffer);
    row_draw(self->size,self->cells,8, buffer);
    _board_draw_separator(buffer);
    return 0;
}

int board_put_in_position(board_t* self, int value, int row, int cloumn) {

    return 0;
}
int board_clean(board_t* self) {
    for (size_t i = 0; i < self->size; i++) {
        for (size_t j = 0; j < self->size; j++) {
            cell_restore(&self->cells[i][j]);
        }
    }
    return 0;
}
int board_verify(board_t* self, int* win) {

    return 0;
}

void _board_draw_line(char* buffer) {
    printf(":%s",buffer);
    char* aux =  "U---+---+---U---+---+---U---+---+---U\n";
    strcat(buffer,aux);
}

void _board_draw_separator(char* buffer) {
    char* aux = "U===========U===========U===========U\n";
    strcat(buffer,aux);
    printf("%s",buffer);
}