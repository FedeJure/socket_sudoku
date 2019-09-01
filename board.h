#ifndef _BOARD_E_
#define _BOARD_E_
#include "row.h"

typedef struct {
    cell_t*** cells;
    int* size;
} board_t;

int board_init(board_t *self,int size, int values[size][size]);
int board_release(board_t* self);
int _board_init_storage(board_t* self, int size);
int _board_init_cells(board_t* self, int size, int values[size][size]);
int _board_init_rows(board_t* self);
int board_draw(board_t* self);
    
#endif