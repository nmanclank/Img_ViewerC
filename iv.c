#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) 
{
    printf("Hello, World!\n");
    

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", 
                                           SDL_WINDOWPOS_CENTERED, 
                                           SDL_WINDOWPOS_CENTERED, 
                                           800, 600, 0); // Create the actual window 

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow); // Getting the surface inside window
    SDL_FillRect(psurface, NULL, 0x000000FF); // Fill the "Surface" with the color blue
    SDL_UpdateWindowSurface(pwindow); // Update the surface inside of our window
    SDL_Delay(3000); 
    SDL_FillRect(psurface, NULL, 0x00FF0000); // Fill the "Surface" with the color red
    SDL_UpdateWindowSurface(pwindow); // Update the surface inside of our window



    SDL_Delay(3000); 
}