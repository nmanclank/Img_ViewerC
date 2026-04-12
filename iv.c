#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) // <--- Add these arguments
{
    printf("Hello, World!\n");
    
    // Initialize SDL (Mandatory for the window to actually appear)
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", 
                                           SDL_WINDOWPOS_CENTERED, 
                                           SDL_WINDOWPOS_CENTERED, 
                                           800, 600, 0);

    SDL_Delay(3000); 
}