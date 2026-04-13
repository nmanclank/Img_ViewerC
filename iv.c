#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>



int main(int argc, char *argv[]) 
{

    #ifdef _WIN32
    #include <fcntl.h>
    #include <io.h>
    // Set stdin to binary mode so Windows doesn't touch the bytes
    _setmode(_fileno(stdin), _O_BINARY);
    #endif

    // printf("Hello, World!\n");
    // const int width = 900;
    // const int height = 600;

    FILE *pin = stdin; // File pointer for input
    char *pthroway = calloc(1000, sizeof(char));
    //Read first line (Specifies P3 or P6)
    fgets(pthroway,1000,pin);
    // Read second line (Comments) IGNORE for now /  trash it
    fgets(pthroway,1000,pin);
    //free(pthroway);
    // Read third line (Dimensions of image file width and height)
    char *pdimensions = calloc(1000, sizeof(char));
    fgets(pdimensions,1000,pin);
    // Read and parse fourth line (Maximum color value) 
    // going to ignore for now. Maybe I will come back and work on actually dealing with this later.
    fgets(pthroway,1000,pin);
    free(pthroway);

    int width = -1;
    int height = -1;
    sscanf(pdimensions,"%d %d\n", &width, &height);
    free(pdimensions); // Free dimensions pointer // no longer need
    printf("width=%d, height=%d\n", width, height);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", 
                                           SDL_WINDOWPOS_CENTERED, 
                                           SDL_WINDOWPOS_CENTERED, 
                                           width, height, 0); // Create the actual window 

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow); // Getting the surface inside window

    // Uint8 r,g,b;
    // r=0x1A;
    // g = b = 0;

    

    // int x=50, y=50; // define xy for pixel to draw
    SDL_Rect pixel = (SDL_Rect){0,0,1,1};// Create a single pixel of xy 1x1

    //Uint32 color = 0;// temp value for color 
    for(int y = 0; y < height; y++) 
    {
        for(int x = 0; x < width; x++) 
        {
                Uint8 r,g,b;
                //get colors from stdin
                // r=(char) getchar(); //
                // g=(char) getchar(); 
                // b=(char) getchar();
                r = (Uint8)fgetc(stdin);
                g = (Uint8)fgetc(stdin);
                b = (Uint8)fgetc(stdin);

                Uint32 color = SDL_MapRGB(psurface->format,r,g,b);

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