#ifndef _CELL_E
#define _CELL_E

typedef struct {
    int number;
    int editable;
} cell_t;

int cell_restore(cell_t* self);

#endif