#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_set>
#include <queue>

using namespace std;

int NO_COLOR = 0;
int BLACK = 1;
int WHITE = 2;
int RED = 3;

struct Cell {
    int r;
    int c;
    int color;

    Cell(int _r, int _c) {
        r = _r;
        c = _c;
        color = NO_COLOR;
    }
};

Cell colorOneCell(queue<Cell> &cells, int color) {
    Cell curCell = cells.front();
    cells.pop();
    curCell.color = color;

    return curCell;
}

Cell getNextColoredCell(queue<Cell> &blackCells, queue<Cell> &whiteCells, int forbiddenColor) {
    int color;

    if(blackCells.size() == 0) {
        color = forbiddenColor != WHITE ? WHITE : RED; 
        return colorOneCell(whiteCells, color);
    }
    else if(whiteCells.size() == 0) {
        color = forbiddenColor != BLACK ? BLACK : RED;
        return colorOneCell(blackCells, color);
    }
    else if(forbiddenColor != BLACK) {
        return colorOneCell(blackCells, BLACK);
    }
    else {
        return colorOneCell(whiteCells, WHITE);
    }
}

int main() {
    int n, c;
    queue<Cell> blackCells;
    queue<Cell> whiteCells;

    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if((i+j)%2 == 0) {
                blackCells.push(Cell(i, j));
            }
            else {
                whiteCells.push(Cell(i, j));
            }
        }
    }

    for(int i=0;i<n*n;i++) {
        cin >> c;
        Cell cell = getNextColoredCell(blackCells, whiteCells, c);
        cout << cell.color << " " << cell.r+1 << " " << cell.c+1 << "\n";
    }    
} 