#ifndef _BOARD_E_
#define _BOARD_E_
#include "row.h"

typedef struct {
    cell_t cells[9][9];
    int size;
} board_t;

int board_init(board_t *self,int size, int values[size][size]);
int board_release(board_t* self);
int _board_init_storage(board_t* self, int size);
int _board_init_cells(board_t* self, int size, int values[size][size]);
int _board_init_rows(board_t* self);
void _board_draw_line(char* buffer);
void _board_draw_separator(char* buffer);
int board_draw(board_t* self, char* buffer);
int board_put_in_position(board_t* self, int value, int row, int cloumn);
int board_clean(board_t* self);
int board_verify(board_t* self, int* win);
    
#endif