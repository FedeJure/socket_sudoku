#include "board.h"
#include "row.h"
#include <stdio.h>
#include <stdlib.h>

int board_init(board_t *self, int values[][9], int size) {
    self->size = size;
    _board_init_rows(self, values, size);
    _board_init_columns(self, values, size);
    return 0;
}

int board_release(board_t* self) {
    row_release(self->columns);
    row_release(self->rows);
    free(self->columns);
    free(self->rows);

    return 0;
}

int _board_init_rows(board_t* self, int values[][9], int size) {
    row_t* rows = malloc(size * sizeof(row_t));
    self->rows = rows;

    for (int i = 0; i<size; i++) {
        int row_values[size];
        row_t* row = &self->rows[i];
        for (int j = 0; j < size; j++) {
            row_values[j] = values[i][j];
        }
        row_init(row, row_values, size);
    }
    return 0;
}

int _board_init_columns(board_t* self, int values[][9], int size) {
    column_t* columns = malloc(size * sizeof(row_t));
    self->columns = columns;

    for (int i = 0; i < size; i++)
    {
        int column_values[size];
        column_t* column = &self->rows[i];
        for (int j = 0; i < size; j++) {
            column_values[j] = values[j][i];
        }
        
        row_init(column, column_values, size);
    }
    return 0;
}

int board_draw(board_t* self) {
    printf("Dibujando tablero\n");    
    for (size_t i = 0; i < self->size; i++) {
        row_draw(&self->rows[i]);
    }
    
    return 0;
}
