// Copyright [2019] <Federico Jure>
#include "./sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 1
#define SUCCESS 0

int sudoku_init(sudoku_t* self) {
    int board_values[SUDOKU_SIZE][SUDOKU_SIZE] = {0};
    _sudoku_read_source_file(board_values);
    _sudoku_init_cells(self, board_values);

    return SUCCESS;
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
    return SUCCESS;
}
int sudoku_put_in_position(sudoku_t* self, int value, int row, int column) {
    if (value > 9 || value < 0 || row > 9 || row < 0 || column > 9 || column < 0) {
        return ERROR;
    }
    if (self->cells[row-1][column-1].editable == 0) {
        return ERROR;
    }
    self->cells[row-1][column-1].number = value;
    return SUCCESS;
}
int sudoku_clean(sudoku_t* self) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            if (self->cells[i][j].editable == 1) {
                self->cells[i][j].number = 0;
            }
        }

    }

    return SUCCESS;
}
int sudoku_verify(sudoku_t* self) {
    int zone_size = 3;
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        int row_verify[SUDOKU_SIZE+1] = {0};
        int column_verify[SUDOKU_SIZE+1] = {0};
        int zone_verify[SUDOKU_SIZE+1] = {0};
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            if (self->cells[i][j].number != 0 && row_verify[self->cells[i][j].number] != 0) {
                return ERROR;
            }
            if (self->cells[j][i].number != 0 && column_verify[self->cells[j][i].number] != 0) {
                return ERROR;
            }
            int zone_row = (j / zone_size) + zone_size * (i / zone_size);
            int zone_column = (j % zone_size) + zone_size * (i % zone_size);
            if (self->cells[zone_row][zone_column].number != 0 && zone_verify[self->cells[zone_row][zone_column].number] != 0) {
                return ERROR;
            }
            row_verify[self->cells[i][j].number] = 1;
            column_verify[self->cells[j][i].number] = 1;
            zone_verify[self->cells[zone_row][zone_column].number] = 1;
        }
    }
    return SUCCESS;
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
    return SUCCESS;

}

int sudoku_get_board(sudoku_t* self, int*** values) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            *values[i][j] = self->cells[i][j].number;
        }

    }
    return SUCCESS;
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
    return SUCCESS;
}

void _sudoku_draw_line(char* buffer) {
    char* aux =  "U---+---+---U---+---+---U---+---+---U\n";
    strcat(buffer,aux);
}

void _sudoku_draw_separator(char* buffer) {
    char* aux = "U===========U===========U===========U\n";
    strcat(buffer,aux);
}

int row_draw(int size, cell_t cells[size][size], int row, char* buffer) {
    char values[size];
    for (int i = 0; i < size; i++) {
        if (cells[row][i].number == 0) values[i] = 32;
        else values[i] = cells[row][i].number+'0';
    }

    char* format = "U %c | %c | %c "; //12
    char aux[strlen(format)];
    sprintf(aux, format, values[0],values[1],values[2]);
    strcat(buffer, aux);

    sprintf(aux, format, values[3],values[4],values[5]);
    strcat(buffer, aux);

    sprintf(aux, format, values[6],values[7],values[8]);

    strcat(buffer, aux);

    strcat(buffer, "U\n");
    return 0;
}