#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include "linedrawer.h"

#define WIDTH 800
#define HEIGHT 600

using namespace std;

int main() {
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Hello world", WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
    LineManager linemanager(WIDTH, HEIGHT);

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
    int triangley[3] = {40, 80, 60};
    int trianglex[3] = {100,100,50};
    
    while(running) {
        
        time += 0.01;
        while (SDL_PollEvent(&event)) if(event.type == SDL_EVENT_QUIT) running = false;
        for (int i = 0; i < WIDTH*HEIGHT; i++) linemanager.pixels[i] = 0xFF000000; //Clear Screen maually like an idiot

        i[0] = cos(float(time)); i[1] = sin(float(time)); //for rX; {x,y}
        j[0] = sin(float(time)); j[1] = (-cos(float(time))); //for rY; {x,y}
linemanager.drawTriangleFilled(trianglex, triangley);
        //linemanager.drawLine2D(100, 100, 200, 0, setPixel);
        //cout << sin(time)*2 << endl;
        //cout << cos(time)*2 << endl;
        //setPixel(sin(time)*2, cos(time)*2, 255, 0, 0);
 
        //linemanager.drawLine2DCartesian(0, 0, sin(time)*100, cos(time)*100, WIDTH/2, HEIGHT/2, 1, setPixel);
        
        SDL_UpdateTexture(texture, NULL, linemanager.pixels.data(), WIDTH * 4);
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