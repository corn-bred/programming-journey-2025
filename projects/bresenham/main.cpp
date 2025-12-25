#include <iostream>
#include <cmath>
#include <Windows.h>
#include <map>
#define WIDTH 75
#define HEIGHT 50

using namespace std;

class inputManager {
    private:
    map<string, bool> keyStates;
};



int grid[WIDTH][HEIGHT] = {0};

void gridClear() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
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
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
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

void drawLineDetail(int x1, int y1, int x2, int y2, int multiplier, bool halveY) {
    float tmp = (halveY == true) ? 2 : 1;
    //cout << x1 << ' ' << y1 << endl;
    drawLine((x1* multiplier+WIDTH/2) ,((-y1/tmp* multiplier)+HEIGHT/2 ),(x2 * multiplier+WIDTH/2),( (-y2/tmp * multiplier)+HEIGHT/2));
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
    float i[2] = {1,0}, j[2] = {0,1}; //x and y axis manipulation for rotation
    
    int square[4][2] = { // {x, y}
        {10, 10}, 
        {10, -10}, 
        {-10, -10}, 
        {-10, 10}
    };
    int line[2][2] = {
        {0,10},
        {-10,-10}
    };
int tmp, tmp2;
    for (float time = 0; time < 10; time+=0.2) {
        
        i[0] = cos(float(time)); i[1] = sin(float(time)); //for rX; {x,y}
        j[0] = sin(float(time)); j[1] = (-cos(float(time))); //for rY; {x,y}
        //tmp = cos(float(time))*10;
        //tmp2 = sin(float(time))*10;
        gridClear();
        for (int idx = 0; idx < 4; idx++) {
            //drawLine((x[0]*line[0][0] + x[1]*line[0][1]) +20,   (y[0]*line[0][0] + y[1]*line[0][1]) +20  ,   (x[0]*line[1][0] + x[1]*line[1][1]) +20  ,   (y[0]*line[1][0] + y[1]*line[1][1]) +20  );
            //drawLineDetail( (int) (x[0]*10), (int) (x[1]*0), 0,0);
            drawLineDetail( (int) ( (i[0] * (float)(square[idx][0])) + (j[0]* (float)(square[idx][1])) ), (int) ( (i[1]* (float)(square[idx][0])) + (j[1]* (float)(square[idx][1])) ) , (int) ( (i[0] * (float)(square[(idx+1)%4][0])) + (j[0]* (float)(square[(idx+1)%4][1])) ), (int) ( (i[1]* (float)(square[(idx+1)%4][0])) + (j[1]* (float)(square[(idx+1)%4][1])) ),1,false);
            //drawLineDetail( (int) (y[0]*10+x[0]*10), (int) (y[1]*10+x[1]*10), 0 , 0 );
            //drawLineDetail( (int) (x[0]* line[0][0] + y[0]* line[1][0]) , (int) (x[1]*line[0][1]+y[1]*line[1][1]), (int) (0) , (int) (0));
        }
    clear();
    printGrid();
    Sleep(16);
}
    return 0;
}