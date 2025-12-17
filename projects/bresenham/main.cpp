#include <iostream>

using namespace std;

int grid[21][21] = {0};

void printGrid() {
    for (int y = 0; y < 21; y++) {
        for (int x = 0; x < 21; x++) {
            switch(grid[x][y]) {
                case 0: cout << "-"; break;
                case 1: cout << "#"; break;
                case 2: cout << "."; break;
                default: break;
            }
            
        }
        cout << endl;
    }
}

void draw(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int dxy1 = (dx >= dy) ? dy : dx;
    int dxy2 = (dx >= dy) ? dx : dy;
    int xy1 = (dx >= dy) ? x1 : y1; // Is difference x bigger than difference y?
    int xy2 = (dx >= dy) ? x2 : y2; // Is difference y bigger than difference x?
    int stepdirY = (y1 < y2) ? 1 : -1;
    int y = (dx >= dy) ? y1 : x1;
    int error = 0;

    for (int x = xy1; x <= xy2; x++) {
        cout << "(" << x << ", " << y << ")" << endl;
        grid[x][y] = 1;
        error += dxy1;
        cout << error*2 << endl;
        if (2*error >= dxy2) { //same as | error/dx >= 0.5 | error >= 0.5*dx | error >= dx*0.5 | error/0.5 >= dx | error*2 >= dx | NO FLOATING POINT 
            y+=stepdirY;
            error -= dxy2;
            //cout << "UP: "<< error << endl;
        }
        
    }
    grid[x1][y1] = 2;
    grid[x2][y2] = 2;
}

/*
Run these through your implementation
Test 1: (0,0) → (5,2)   Should be 6 points
Test 2: (0,0) → (9,2)   Should be 10 points  
Test 3: (5,5) → (10,5)  Horizontal, 6 points
Test 4: (5,5) → (5,10)  Vertical, 6 points
Test 5: (0,5) → (5,0)   Negative slope, 6 points
*/

int main () {
    draw(0,0,5,10);
    printGrid();
    return 0;
}