#ifndef _ROW_E_
#define _ROW_E_
#include "cell.h"

typedef struct {
    cell_t** cells;
    int size;
} row_t, column_t, sector_t;

int row_init(row_t* self, cell_t* cells, int size);
int row_release(row_t* self);
int row_draw(row_t* self);

#endif