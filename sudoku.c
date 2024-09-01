#include "sudoku.h"

int main(){
    int** puzzle;
    puzzle  = createSudoku();
    printSudoku(puzzle);
    bool solved = solveSudoku(0,0,puzzle);
    if(solved) printSudoku(puzzle);
    else printf("could not solve puzzle");
    return 0;
}