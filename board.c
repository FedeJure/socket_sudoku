#include "board.h"
#include "row.h"
#include <stdio.h>
#include <stdlib.h>

int board_init(board_t *self, int values[][9], int size) {
    _board_init_storage(self, size);
    _board_init_cells(self, values);
    _board_init_rows(self);

    printf("Tablero inicializado\n");    
    return 0;
}

int board_release(board_t* self) {
    int size = *self->size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            free(&self->cells[i]);
        }
    }
    row_release(self->columns);
    row_release(self->rows);
    free(self->columns);
    free(self->rows);
    free(self->cells);
    return 0;
}

int _board_init_storage(board_t* self, int size) {
    int* size_storage = malloc(sizeof(int));
    self->size = size_storage;
    *self->size = size;
    row_t* rows = malloc(size * sizeof(row_t*));
    self->rows = rows;
    column_t* columns = malloc(size * sizeof(column_t*));
    self->columns = columns;
    cell_t* storage_cells = malloc(size * sizeof(cell_t*));
    self->cells = storage_cells;
    return 0;
}

int _board_init_cells(board_t* self, int values[][9]) {
    printf("Creando celdas\n");  
    int size = *self->size;
    for (int i = 0; i<size; i++) {
        
        for (int j = 0; j < size; j++) {
            printf("Valor: %d\n",values[i][j]); 
            printf("Creando celda numero: %d, %d\n",i,j); 
            cell_t* cell = &self->cells[i];
            printf("Creando celda numero: %d, %d\n",i,j);
            cell->number = values[i][j];
            printf("Creando celda numero: %d, %d\n",i,j);
            cell->original_number = values[i][j];
        }
    }
    return 0;
}

int _board_init_rows(board_t* self) {
    printf("Creando filas y columnas con celdas\n");  
    int size = *self->size;
    for (int i = 0; i<size; i++) {
        row_t* row = &self->rows[i];
        column_t* column = &self->columns[i];
        cell_t* row_values[size];
        cell_t* columns_values[size];
        for (int j = 0; j < size; j++) {
            row_values[j] = &self->cells[i];
            columns_values[j] = &self->cells[j];
        }
        row_init(row, *row_values, size);
        row_init(column, *columns_values, size);
    }

    return 0;
}

int board_draw(board_t* self) {
    printf("Dibujando tablero\n"); 
    int size = *self->size;   
    for (size_t i = 0; i < size; i++) {
        row_draw(&self->rows[i]);
    }
    
    return 0;
}
