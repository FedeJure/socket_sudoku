#include "sudoku.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sudoku_init(sudoku_t* self) {
    printf("Initializing sudoku\n");
    board_t board;
    int board_values[SUDOKU_SIZE][SUDOKU_SIZE];
    self->board = &board;
    _sudoku_read_source_file(board_values);
    board_init(self->board, SUDOKU_SIZE, board_values);
    
    return 0; 
}

int sudoku_release(sudoku_t* self) {
    board_release(self->board);
    return 0;
}

int sudoku_draw(sudoku_t* self, char* buffer) {
    board_draw(self->board, buffer);
    return 0;
}
int sudoku_put_in_position(sudoku_t* self, int value, int row, int column) {
    board_put_in_position(self->board, value, row, column);
    return 0;
}
int sudoku_clean(sudoku_t* self) {
    board_clean(self->board);
    return 0;
}
int sudoku_verify(sudoku_t* self, int* win) {
    board_verify(self->board, win);
    return 0;
}

int _sudoku_read_source_file(int values[SUDOKU_SIZE][SUDOKU_SIZE]) {
    FILE* file;
    file = fopen(FILE_NAME, "r");
    int row_number = 0;
    while(feof(file) == 0) {
        int res = fscanf(file,"%d %d %d %d %d %d %d %d %d",
        &values[row_number][0],
        &values[row_number][1],
        &values[row_number][2],
        &values[row_number][3],
        &values[row_number][4],
        &values[row_number][5],
        &values[row_number][6],
        &values[row_number][7],
        &values[row_number][8]
        );
        if (res == -1) continue;
        row_number++;
    }

    fclose(file);
    return 0;

}