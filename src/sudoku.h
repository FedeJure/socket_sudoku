#ifndef _SUDOKU_E_
#define _SUDOKU_E_

#include "cell.h"

#define SUDOKU_SIZE 9
#define FILE_NAME "board.txt"
#define FILE_SIZE 171

typedef struct {
    cell_t cells[SUDOKU_SIZE][SUDOKU_SIZE];
} sudoku_t;

int sudoku_init(sudoku_t* self);
int sudoku_draw(sudoku_t* self, char* buffer);
int sudoku_put_in_position(sudoku_t* self, int value, int row, int cloumn);
int sudoku_clean(sudoku_t* self);
int sudoku_verify(sudoku_t* self);
int _sudoku_read_source_file(int values[SUDOKU_SIZE][SUDOKU_SIZE]);
int sudoku_get_board(sudoku_t* self, int*** values);
int _sudoku_init_cells(sudoku_t* self, int values[SUDOKU_SIZE][SUDOKU_SIZE]);
void _sudoku_draw_line(char* buffer);
void _sudoku_draw_separator(char* buffer);
int send_length(int fd, int length);
int row_draw(int size, cell_t cells[size][size], int row, char* buffer);


#endif