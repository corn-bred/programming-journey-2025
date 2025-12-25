#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include "linedrawer.h"

#define WIDTH 800
#define HEIGHT 600

using namespace std;

vector<uint32_t> pixels(WIDTH * HEIGHT);

void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
    pixels[y * WIDTH + x] = (0xFF << 24) | (r << 16) | (g << 8) | b;
}

int main() {
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Hello world", WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    LineManager linemanager;

    SDL_Event event;
    
    bool running = true;

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

    float time = 0;

    while(running) {
        time += 0.01;
        while (SDL_PollEvent(&event)) if(event.type == SDL_EVENT_QUIT) running = false;
        for (int i = 0; i < WIDTH*HEIGHT; i++) pixels[i] = 0xFF000000; //Clear Screen maually like an idiot

        i[0] = cos(float(time)); i[1] = sin(float(time)); //for rX; {x,y}
        j[0] = sin(float(time)); j[1] = (-cos(float(time))); //for rY; {x,y}

        //linemanager.drawLine2D(100, 100, 200, 0, setPixel);
        for (int idx = 0; idx < 4; idx++) {
            //drawLine((x[0]*line[0][0] + x[1]*line[0][1]) +20,   (y[0]*line[0][0] + y[1]*line[0][1]) +20  ,   (x[0]*line[1][0] + x[1]*line[1][1]) +20  ,   (y[0]*line[1][0] + y[1]*line[1][1]) +20  );
            //drawLineDetail( (int) (x[0]*10), (int) (x[1]*0), 0,0);
            linemanager.drawLine2DCartesian(  (i[0] * (float)(square[idx][0])) + (j[0]* (float)(square[idx][1])) ,  (i[1]* (float)(square[idx][0])) + (j[1]* (float)(square[idx][1])) , (i[0] * (float)(square[(idx+1)%4][0])) + (j[0]* (float)(square[(idx+1)%4][1])) , (i[1]* (float)(square[(idx+1)%4][0])) + (j[1]* (float)(square[(idx+1)%4][1])), WIDTH/2, HEIGHT/2, 10, setPixel);
            //drawLineDetail( (int) (y[0]*10+x[0]*10), (int) (y[1]*10+x[1]*10), 0 , 0 );
            //drawLineDetail( (int) (x[0]* line[0][0] + y[0]* line[1][0]) , (int) (x[1]*line[0][1]+y[1]*line[1][1]), (int) (0) , (int) (0));
        }
        cout << sin(time)*2 << endl;
        cout << cos(time)*2 << endl;
        //setPixel(sin(time)*2, cos(time)*2, 255, 0, 0);
 
        //linemanager.drawLine2DCartesian(0, 0, sin(time)*100, cos(time)*100, WIDTH/2, HEIGHT/2, 1, setPixel);

        
        SDL_UpdateTexture(texture, NULL, pixels.data(), WIDTH * 4);
        SDL_RenderTexture(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}