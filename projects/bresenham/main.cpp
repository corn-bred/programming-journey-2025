#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;



int grid[31][31] = {0};

void gridClear() {
    for (int y = 0; y < 31; y++) {
        for (int x = 0; x < 31; x++) {
            grid[x][y] = 0;
            
        }
    }
}

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printGrid() {
    for (int y = 0; y < 31; y++) {
        for (int x = 0; x < 31; x++) {
            switch(grid[x][y]) {
                case 0: cout << " "; break;
                case 1: cout << "#"; break;
                case 2: cout << "."; break;
                default: break;
            }
            
        }
        cout << endl;
    }
}



void drawLine(int x1, int y1, int x2, int y2) {
    //cout << "(" << x1 << ", " << y1 << ")" << endl;
    //cout << "(" << x2 << ", " << y2 << ")" << endl;
    
    int dx = x2-x1;
    int dy = y2-y1;
    //cout  << y2-y1 << endl;
    int sx = ( x2-x1 < 0 ) ? -1 : 1;
    int sy = ( y2-y1 < 0 ) ? -1 : 1;
    //cout << sx << endl;
    int error = 0;
    int tmp = 0;

    if (abs(dx) >= abs(dy)) {
        
            
            int y = y1;
            
            for (int x = x1; x != x2 + sx; x+=sx) {
                tmp++;
                grid[x][y] = 1;
                
                error += (abs(dy)*2);
                
                if (error >= abs(dx)) {
                    y+=sy;
                    error -= abs(dx) * 2;
                }

                //cout << error << endl;
                
            }
            
        
        
    } else {
        int x = x1;
            for (int y = y1; y != y2 + sy; y+=sy) {
                tmp++;
                grid[x][y] = 1;
                //cout << "(" << x << ", " << y << ")" << endl;
                error += (abs(dx)*2);
                
                if (error >= abs(dy)) {
                    x+=sx;
                    error -= abs(dy) * 2;
                }

                //cout << error << endl;
            }
    }
    cout << tmp << endl;
    grid[x1][y1] = 2;
    grid[x2][y2] = 2;
    
}

void drawLineCartesian(int x1, int y1, int x2, int y2,int xOrig, int yOrig) {
    drawLine(x1+xOrig,(-y1)+yOrig,x2+xOrig,(-y2)+yOrig);
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
    float x[2] = {0,1}, y[2] = {1,0}; //x and y axis manipulation for rotation
    

    for (float time = 0; time < 10; time+=0.2) {
        
        x[0] = cos(float(time)); x[1] = -sin(float(time)); //for rX; {x,y}
        y[0] = sin(float(time)); y[0] = cos(float(time)); //for rY; {x,y}
        int square[4][2] = { // {x, y}
            {10, 10}, 
            {10, -10}, 
            {-10, -10}, 
            {-10, 10}
        };
        int line[2][2] = {
            {10,10},
            {-10,-10}
        };
        gridClear();
        for (int i = 0; i < 4; i++) {
            //drawLine((x[0]*line[0][0] + x[1]*line[0][1]) +20,   (y[0]*line[0][0] + y[1]*line[0][1]) +20  ,   (x[0]*line[1][0] + x[1]*line[1][1]) +20  ,   (y[0]*line[1][0] + y[1]*line[1][1]) +20  );
        
            drawLineCartesian( (int) (cos(time)*square[i%4][0]) , (int) (-sin(time)*square[i%4][1]/2), (int) (sin(time)*square[(i+1)%4][0]) , (int) (cos(time)*square[(i+1)%4][1]/2), 20,20);
        }
    clear();
    printGrid();
    Sleep(100);
}
    return 0;
}