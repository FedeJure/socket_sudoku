#ifndef _BOARD_E_
#define _BOARD_E_
#include "row.h"

typedef struct {
    row_t* rows;
    column_t* columns;
    short int size;
} board_t;

int board_init(board_t *self, int values[][9], int size);
int board_release(board_t* self);
int _board_init_rows(board_t* self, int values[][9], int size);
int _board_init_columns(board_t* self, int values[][9], int size);
int board_draw(board_t* self);
    
#endif