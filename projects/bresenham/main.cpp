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
    int dx = x2-x1;
    int dy = y2-y1;
    int y = y1;
    int error = 0;
    
    for (int x = x1; x < x2; x++) {
        
        if (error > dx) {
            y++;
            error -= dx;
        } else {
            error += dy*2;
        }
        
        cout << error << endl;
        grid[x][y] = 1;
        
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
    
    draw(0,0,9,2);
    
    printGrid();
    return 0;
}