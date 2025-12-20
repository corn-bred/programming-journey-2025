#include <iostream>

using namespace std;

int grid[41][41] = {0};

void printGrid() {
    for (int y = 0; y < 41; y++) {
        for (int x = 0; x < 41; x++) {
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



void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2-x1;
    int dy = y2-y1;
    cout  << y2-y1 << endl;
    int sx = ( x2-x1 < 0 ) ? -1 : 1;
    int sy = ( y2-y1 < 0 ) ? -1 : 1;
    cout << sx << endl;
    int error = 0;
    
    if (abs(dx) >= abs(dy)) {
        
            
            int y = y1;
            for (int x = x1; x != x2 + sx; x+=sx) {
                grid[x][y] = 1;
                error += (abs(dy)*2);
                
                if (error >= abs(dx)) {
                    y+=sy;
                    error -= abs(dx) * 2;
                }

                cout << error << endl;
            }
        
        
    } else {
        int x = x1;
            for (int y = y1; y != y2 + sy; y+=sy) {
                grid[x][y] = 1;
                error += (abs(dx)*2);
                
                if (error >= abs(dy)) {
                    x+=sx;
                    error -= abs(dy) * 2;
                }

                cout << error << endl;
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
    
    // 8-direction test from center (20,10)
int cx = 20, cy = 20;

// Gentle slopes (X-major)
drawLine(cx, cy, cx+15, cy+5);   // Octant 1 (0-45°)
drawLine(cx, cy, cx+15, cy-5);   // Octant 8 (315-360°)
drawLine(cx, cy, cx-15, cy+5);   // Octant 4 (135-180°)
drawLine(cx, cy, cx-15, cy-5);   // Octant 5 (180-225°)

// Steep slopes (Y-major)  
drawLine(cx, cy, cx+5, cy+15);   // Octant 2 (45-90°)
drawLine(cx, cy, cx-5, cy+15);   // Octant 3 (90-135°)
drawLine(cx, cy, cx+5, cy-15);   // Octant 7 (270-315°)
drawLine(cx, cy, cx-5, cy-15);   // Octant 6 (225-270°)

// Special cases
drawLine(cx, cy, cx+10, cy);     // Horizontal right
drawLine(cx, cy, cx-10, cy);     // Horizontal left
drawLine(cx, cy, cx, cy+10);     // Vertical down
drawLine(cx, cy, cx, cy-10);     // Vertical up
    
    printGrid();
    return 0;
}