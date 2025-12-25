#include "linedrawer.h"

void LineManager::drawLine2D(int x1, int y1, int x2, int y2, void (*operation)(int x, int y, uint8_t r, uint8_t g, uint8_t b)) {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x2 - x1 < 0) ? -1 : 1;
        int sy = (y2 - y1 < 0) ? -1 : 1;
        int error = 0;

    
        if (dx < dy) {
            int x = x1;

            for (int y = y1; y != y2 + sy; y += sy) {
                operation(x, y, 255, 255, 255);

                error += abs(dx);
                
                if (error *2 >= abs(dy)) {
                    error -= abs(dy);
                    x+=sx;
                }
            }
        } else {

            int y = y1;

            for (int x = x1; x != x2 + sx; x += sx) {
                operation(x, y, 255, 255, 255);

                error += abs(dy);
        
                if (error *2 >= abs(dx)) {
                    error -= abs(dx);
                    y+=sy;
                }
            }
        }
    }
    
void LineManager::drawLine2DCartesian(float x1, float y1, float x2, float y2, int xorigin, int yorigin, int scale, void (*operation)(int x, int y, uint8_t r, uint8_t g, uint8_t b)) {
        drawLine2D(x1 *scale +xorigin, -y1 *scale +yorigin, x2 *scale +xorigin, -y2 *scale +yorigin, operation);
    }
void LineManager::drawLineDetail(int x1, int y1, int x2, int y2, int multiplier, bool halveY, void (*operation)(int x, int y, uint8_t r, uint8_t g, uint8_t b)) {
    float tmp = (halveY == true) ? 2 : 1;
    //cout << x1 << ' ' << y1 << endl;
    drawLine2D((x1* multiplier+200) ,((-y1/tmp* multiplier)+200 ),(x2 * multiplier+200),( (-y2/tmp * multiplier)+200), operation);
}

