#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) 
{
    // printf("Hello, World!\n");
    const int width = 900;
    const int height = 600;
    

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", 
                                           SDL_WINDOWPOS_CENTERED, 
                                           SDL_WINDOWPOS_CENTERED, 
                                           800, 600, 0); // Create the actual window 

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow); // Getting the surface inside window

    Uint8 r,g,b;
    r=0x1A;
    g = b = 0;

    Uint32 color = SDL_MapRGB(psurface->format,r,g,b);

    // int x=50, y=50; // define xy for pixel to draw
    SDL_Rect pixel = (SDL_Rect){0,0,1,1};// Create a single pixel of xy 1x1
    for(int x = 0; x < width; x++) \
    {
        for(int y = 0; y < height; y++) 
        {
                pixel.x = x;
                pixel.y = y;
                SDL_FillRect(psurface, &pixel, color); // Fill the "Surface" with  color 

        }
    }
    // SDL_Rect pixel =(SDL_Rect){x,y,1,1}; // Create a single pixel of xy 1x1
    // SDL_FillRect(psurface, &pixel, color); // Fill the "Surface" with  color 
    SDL_UpdateWindowSurface(pwindow); // Update the surface inside of our window
    SDL_Delay(3000); 


}