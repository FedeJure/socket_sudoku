#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "row.h"


int sudoku_init(sudoku_t* self) {
    int board_values[SUDOKU_SIZE][SUDOKU_SIZE] = {0};
    _sudoku_read_source_file(board_values);
    _sudoku_init_cells(self, board_values);
    
    return 0; 
}

int sudoku_release(sudoku_t* self) {
    // board_release(&self->board);
    return 0;
}

int sudoku_draw(sudoku_t* self, char* buffer) {
    _sudoku_draw_separator(buffer);
    row_draw(SUDOKU_SIZE,self->cells,0, buffer);
    _sudoku_draw_line(buffer);
    row_draw(SUDOKU_SIZE,self->cells,1, buffer);
    _sudoku_draw_line(buffer);
    row_draw(SUDOKU_SIZE,self->cells,2, buffer);
    _sudoku_draw_separator(buffer);
    row_draw(SUDOKU_SIZE,self->cells,3, buffer);
    _sudoku_draw_line(buffer);
    row_draw(SUDOKU_SIZE,self->cells,4, buffer);
    _sudoku_draw_line(buffer);
    row_draw(SUDOKU_SIZE,self->cells,5, buffer);
    _sudoku_draw_separator(buffer);
    row_draw(SUDOKU_SIZE,self->cells,6, buffer);
    _sudoku_draw_line(buffer);
    row_draw(SUDOKU_SIZE,self->cells,7, buffer);
    _sudoku_draw_line(buffer);
    row_draw(SUDOKU_SIZE,self->cells,8, buffer);
    _sudoku_draw_separator(buffer);
    return 0;
}
int sudoku_put_in_position(sudoku_t* self, int value, int row, int column) {
    if (value > 9 || value < 0 || row > 9 || row < 0 || column > 9 || column < 0) {
        return -1;
    }
    if (self->cells[row-1][column-1].editable == 0) {
        return -1;
    }
    self->cells[row-1][column-1].number = value;
    return 0;
}
int sudoku_clean(sudoku_t* self) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            if (self->cells[i][j].editable == 1) {
                self->cells[i][j].number = 0;
            }
        }
        
    }
    
    return 0;
}
int sudoku_verify(sudoku_t* self) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        int row_verify[SUDOKU_SIZE+1] = {0};
        int column_verify[SUDOKU_SIZE+1] = {0};
        // int zone_verify[SUDOKU_SIZE+1] = {0};
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            if (self->cells[i][j].number != 0 && row_verify[self->cells[i][j].number] != 0) {
                return -1;
            }
            if (self->cells[j][i].number != 0 && column_verify[self->cells[j][i].number] != 0) {
                return -1;
            }
            // int zone_row = (i / 3) + (3* i/3);
            // int zone_column = (j % 3) + (3* j/3);
            // fprintf(stdout, "%d %d %d %d\n", i,j,zone_row,zone_column);
            // if (self->cells[zone_row][zone_column].number -1 != 0 && zone_verify[self->cells[zone_row][zone_column].number -1] != 0) {
            //     return -1;
            // }
            row_verify[self->cells[i][j].number] = 1;
            column_verify[self->cells[j][i].number] = 1;
            // zone_verify[self->cells[zone_row][zone_column].number] = 1;
        }

    }
    return 0;    
}
    


int _sudoku_read_source_file(int values[SUDOKU_SIZE][SUDOKU_SIZE]) {    
    FILE* file;
    file = fopen(FILE_NAME, "r");
    int row_number = 0;
    while(feof(file) == 0) {
        int res = fscanf(file,"%d %d %d %d %d %d %d %d %d",
        &values[row_number][0],
        &values[row_number][1],
        &values[row_number][2],
        &values[row_number][3],
        &values[row_number][4],
        &values[row_number][5],
        &values[row_number][6],
        &values[row_number][7],
        &values[row_number][8]
        );
        if (res == -1) continue;
        row_number++;
    }

    fclose(file);
    return 0;

}

int sudoku_get_board(sudoku_t* self, int*** values) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            *values[i][j] = self->cells[i][j].number;
        }
        
    }
    return 0;
}

int _sudoku_init_cells(sudoku_t* self, int values[SUDOKU_SIZE][SUDOKU_SIZE]) {
    for (int i = 0; i<SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            cell_t cell;
            self->cells[i][j] = cell;
            self->cells[i][j].number = values[i][j];
            self->cells[i][j].editable = values[i][j] == 0 ? 1 : 0;
        }
    }
    return 0;
}


void _sudoku_draw_line(char* buffer) {
    char* aux =  "U---+---+---U---+---+---U---+---+---U\n";
    strcat(buffer,aux);
}

void _sudoku_draw_separator(char* buffer) {
    char* aux = "U===========U===========U===========U\n";
    strcat(buffer,aux);
}