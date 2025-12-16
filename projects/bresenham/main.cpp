#include <iostream>

using namespace std;

void draw(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    int y = y1;
    int error = 0;
    for (int x = x1; x <= x2; x++) {
        cout << "(" << x << ", " << y << ")" << endl;
        error += dy;

        if (error/dx >= 0.5) {
            y++;
            error -= dx;
        }
    }
}

int main () {
    draw(0,0,2,2);
    return 0;
}