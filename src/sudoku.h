#ifndef _SUDOKU_E_
#define _SUDOKU_E_

#include "board.h"

#define SUDOKU_SIZE 9
#define FILE_NAME "sudoku.txt"
#define FILE_SIZE 171

typedef struct {
    board_t* board;
} sudoku_t;

int sudoku_init(sudoku_t* self);
int sudoku_release(sudoku_t* self);
int sudoku_draw(sudoku_t* self, char* buffer);
int sudoku_put_in_position(sudoku_t* self, int value, int row, int cloumn);
int sudoku_clean(sudoku_t* self);
int sudoku_verify(sudoku_t* self, int* win);
int _sudoku_read_source_file(int values[SUDOKU_SIZE][SUDOKU_SIZE]);
int sudoku_get_board(sudoku_t* self, int*** values);


#endif