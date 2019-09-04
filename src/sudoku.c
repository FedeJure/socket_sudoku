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

  

    board_draw(self->board);
    return 0; 
}

int sudoku_release(sudoku_t* self) {
    board_release(self->board);
    // free(self->board);
    return 0;
}