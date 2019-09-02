#ifndef _SUDOKU_E_
#define _SUDOKU_E_

#include "board.h"

typedef struct {
    board_t* board;
} sudoku_t;

int sudoku_init(sudoku_t* self);
int sudoku_release(sudoku_t* self);

#endif