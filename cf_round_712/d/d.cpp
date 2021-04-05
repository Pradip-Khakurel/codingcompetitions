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

struct ColorInfo {
    int color;
    int r;
    int c;

    ColorInfo(int _color, int _r, int _c) {
        color = _color;
        r = _r;
        c = _c;
    }
};

struct Cell {
    int r;
    int c;

    Cell(int _r, int _c) {
        r = _r;
        c = _c;
    }
};

int NO_COLOR = 0;
int BLACK = 1;
int WHITE = 2;
int RED = 3;

queue<Cell> blacks;
queue<Cell> whites;

bool isOk(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

Cell colorOneCellDiagonally(vector<vector<int>> &grid, queue<Cell> &cells, int color) {
    Cell curCell = cells.front();
    cells.pop();
    grid[curCell.r][curCell.c] = color;

    return curCell;
}

ColorInfo getNextColor(vector<vector<int>> &grid, int forbiddenColor) {
    int color;
    Cell cell(-1, -1);

    if(blacks.size() == 0) {
        color = forbiddenColor != WHITE ? WHITE : RED; 
        cell = colorOneCellDiagonally(grid, whites, color);
    }
    else if(whites.size() == 0) {
        color = forbiddenColor != BLACK ? BLACK : RED;
        cell = colorOneCellDiagonally(grid, blacks, color);
    }
    else if(forbiddenColor != BLACK) {
        color = BLACK;
        cell = colorOneCellDiagonally(grid, blacks, color);
    }
    else {
        color = WHITE;
        cell = colorOneCellDiagonally(grid, whites, color);
    }

    return ColorInfo(color, cell.r, cell.c);
}

int main() {
    int n, c;

    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if((i+j)%2 == 0) {
                blacks.push(Cell(i, j));
            }
            else {
                whites.push(Cell(i, j));
            }
        }
    }

    for(int i=0;i<n*n;i++) {
        cin >> c;
        ColorInfo info = getNextColor(grid, c);

        cout << info.color << " " << info.r+1 << " " << info.c+1 << "\n";
        //cout.flush();
    }    
} 