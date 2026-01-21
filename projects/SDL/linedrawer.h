#pragma once
#include <cmath>
#include <iostream>
#include <stdint.h>
#include <vector>

class LineManager {
    int WIDTH, HEIGHT;
    
    void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, std::vector<uint32_t> *input);
    void drawLine2Dsimple(int x1, int y1, int x2, int y2, std::vector<uint32_t> *mask, int w, int h);
    public:
    std::vector<uint32_t> pixels;
    LineManager() = delete;
    LineManager(int w, int h);
    void drawLine2D(int x1, int y1, int x2, int y2);
    void drawLine2D(int x1, int y1, int x2, int y2, std::vector<uint32_t> *output);
    void drawLine2DGradient(int x1, int y1, uint8_t a1, uint8_t r1, uint8_t g1, uint8_t b1, int x2, int y2, uint8_t a2, uint8_t r2, uint8_t g2, uint8_t b2, void (*operation)(int x, int y, uint8_t r, uint8_t g, uint8_t b));
    void drawLine2DCartesian(float x1, float y1, float x2, float y2, int xorigin, int yorigin, int scale, void (*operation)(int x, int y, uint8_t r, uint8_t g, uint8_t b));
    
    void drawTriangleFilled(int triangleX[3], int triangleY[3]);
};

