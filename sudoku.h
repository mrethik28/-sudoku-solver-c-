#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void printSudoku(int** puzzle);
int** createSudoku();
bool solveSudoku(int row, int col, int** puzzle);
char* findApplicable(int row, int col, int** puzzle);

#endif