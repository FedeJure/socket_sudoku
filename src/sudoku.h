#ifndef _SUDOKU_E_
#define _SUDOKU_E_

#include "board.h"

typedef struct {
    board_t* board;
} sudoku_t;

int sudoku_init(sudoku_t* self);
int sudoku_release(sudoku_t* self);
int sudoku_draw(sudoku_t* self, char* buffer);
int sudoku_put_in_position(sudoku_t* self, int value, int row, int cloumn);
int sudoku_clean(sudoku_t* self);
int sudoku_verify(sudoku_t* self, int* win);

#endif