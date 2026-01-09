#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>

SDL_Window* window;
SDL_Surface* surface;
const int kScreenWidth = 640;
const int kScreenHeight = 480;

void quit() {
    SDL_DestroyWindow(window);
    window = NULL;
    surface = NULL;
    SDL_Quit();
}

void loop() {
    bool quit = false;
    SDL_Event e;
    SDL_zero(e);
    while(!quit) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_FillSurfaceRect( surface,
                       NULL,
                       SDL_MapSurfaceRGB( surface, 10, 150, 10) 
                    );
        

        SDL_UpdateWindowSurface(window);
    }
    
}

int main() {
    bool success = SDL_Init(SDL_INIT_VIDEO);
    if (!success) {
        SDL_Log("Initialization failed... %s\n", SDL_GetError());
        return 2;
    }

    window = SDL_CreateWindow("Field Physics Prototype", kScreenWidth, kScreenHeight, 0);
    if (window == NULL) {
        SDL_Log("Window Creation failed... %s\n", SDL_GetError());
        return 2;
    }

    surface = SDL_GetWindowSurface(window);
  

    loop();
    quit();

    return 0;
}
