#include "row.h"
#include <stdlib.h>
#include <stdio.h>


int row_draw(int size, cell_t* cells[size][size]) {
    if ((size / 3) % 2 != 0) {
        return 1;
    }

    return 0;
}
