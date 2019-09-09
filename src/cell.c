#include "cell.h"

int cell_restore(cell_t* self) {
    if (self->editable == 1) {
        self->number = 0;
    }
    return 0;
}
