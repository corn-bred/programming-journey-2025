#pragma once
#include <cmath>
#include <iostream>
#include <stdint.h>

class LineManager {
    public:
    void drawLine2D(int x1, int y1, int x2, int y2, void (*operation)(int x, int y, uint8_t r, uint8_t g, uint8_t b));
    void drawLine2DCartesian(float x1, float y1, float x2, float y2, int xorigin, int yorigin, int scale, void (*operation)(int x, int y, uint8_t r, uint8_t g, uint8_t b));
    void drawLineDetail(int x1, int y1, int x2, int y2, int multiplier, bool halveY, void (*operation)(int x, int y, uint8_t r, uint8_t g, uint8_t b));
};

