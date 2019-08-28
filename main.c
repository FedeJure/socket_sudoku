#include "main.h"
#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[]) {
    printf("Starting program...\n");

    sudoku_t* sudoku;
    sudoku = malloc(sizeof( sudoku_t));

    sudoku_init(sudoku);

    sudoku_release(sudoku);
    free(sudoku);

    return 0;
}