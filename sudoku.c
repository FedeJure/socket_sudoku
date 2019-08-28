#include "sudoku.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_SIZE 9

int readed[9][9]= {
    {1,2,3,0,0,5,0,9,0},
    {0,0,9,0,1,2,8,6,0},
    {0,0,9,0,1,2,8,6,0},
    {0,0,9,0,1,2,8,6,0},
    {0,0,9,0,1,2,8,6,0},
    {0,0,9,0,1,2,8,6,0},
    {0,0,9,0,1,2,8,6,0},
    {0,0,9,0,1,2,8,6,0},
    {0,0,9,0,1,2,8,6,0},
};


int sudoku_init(sudoku_t* self) {
    printf("Initializing sudoku\n");
    board_t* board = malloc(sizeof(board_t));
    self->board = board;

    board_init(self->board, readed, SUDOKU_SIZE);
    board_draw(self->board);
    return 0; 
}

int sudoku_release(sudoku_t* self) {
    board_release(self->board);
    free(self->board);
    return 0;
}