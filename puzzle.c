#include "sudoku.h"


char* findApplicable(int row, int col, int** puzzle) {
    char* applicable = (char*)malloc(10 * sizeof(char));  // +1 for null terminator
    strcpy(applicable, "111111111");

    for(int i = 0; i < 9; i++) {
        if(puzzle[i][col] != 0) {
            applicable[puzzle[i][col] - 1] = '0';
        }
        if(puzzle[row][i] != 0) {
            applicable[puzzle[row][i] - 1] = '0';
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for(int i = startRow; i < startRow + 3; i++) {
        for(int j = startCol; j < startCol + 3; j++) {
            if(puzzle[i][j] != 0) {
                applicable[puzzle[i][j] - 1] = '0';
            }
        }
    }

    return applicable;
}

bool solveSudoku(int row, int col, int** puzzle) {
    if(row == 9) return true;
    if(col == 9) return solveSudoku(row + 1, 0, puzzle);
    if(puzzle[row][col] != 0) return solveSudoku(row, col + 1, puzzle);

    char* applicable = findApplicable(row, col, puzzle);
    for(int i = 0; i < 9; i++) {
        if(applicable[i] == '1') {
            puzzle[row][col] = i + 1;
            if(solveSudoku(row, col + 1, puzzle)) {
                free(applicable);
                return true;
            }
            puzzle[row][col] = 0;
        }                
    }
    free(applicable);
    return false;
}


int** createSudoku(){
    int array [9][9] = { 0,1,9,     0,0,2,      0,0,0,
                         4,7,0,     6,9,0,      0,0,1,
                         0,0,0,     4,0,0,      0,9,0,

                         8,9,4,     5,0,7,      0,0,0,
                         0,0,0,     0,0,0,      0,0,0,
                         0,0,0,     2,0,1,      9,5,8,

                         0,5,0,     0,0,6,      0,0,0,
                         6,0,0,     0,2,8,      0,7,9,
                         0,0,0,     1,0,0,      8,6,0 };
    int** puzzle = (int**)malloc(9 * sizeof(int*));
    for(int i=0; i<9; i++){
        puzzle[i] = (int*)malloc(9 * sizeof(int));
        for(int j=0; j<9; j++){
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;

}


void printSudoku(int** puzzle){
    int i,j;
    for(i=0; i<9; i++){
        if(i%3 == 0 ) printf("------------------------------\n");
        for(j=0; j<9; j++){
            printf(" %d ", puzzle[i][j]);
            if( (j+1)%3 == 0 ) printf("|");
        }
        printf("\n");
    }
    printf("------------------------------\n");

}