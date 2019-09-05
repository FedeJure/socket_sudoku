#include "sudoku.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_SIZE 9

int readed[9][9]= {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9},
};


int sudoku_init(sudoku_t* self) {
    printf("Initializing sudoku\n");
    board_t board;
    self->board = &board;
    board_init(self->board, SUDOKU_SIZE, readed);
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