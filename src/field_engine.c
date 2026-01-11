#include "field_engine.h"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_video.h>
#include <stdlib.h>

FieldEngine* create_engine(int screenWidth, int screenHeight, void (*loopFunction)()) {
    FieldEngine* engine;

    bool sdlInitSuccess = SDL_Init(SDL_INIT_VIDEO);
    if (!sdlInitSuccess) {
        SDL_Log("SDL Initialization failed... %s\n", SDL_GetError());
        engine = NULL;
    }

    SDL_Window* window = SDL_CreateWindow("Field Physics Prototype", screenWidth, screenHeight, 0);
    if (window == NULL) {
        SDL_Log("SDL Window Creation failed... %s\n", SDL_GetError());
        engine = NULL;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if (surface == NULL) {
        SDL_Log("SDL Surface Creation failed... %s\n", SDL_GetError());
        engine = NULL;
    }

    engine = malloc(sizeof(FieldEngine));
    if (engine == NULL) {
        SDL_Log("FieldEngine was NULL");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL; 
    }
    engine->window = window;
    engine->mainSurface = surface;
    engine->loopFunction = loopFunction;

    return engine;
}


void exit_engine(FieldEngine* engine) {
    SDL_DestroyWindow(engine->window);
    engine->window = NULL;
    SDL_Quit();
    free(engine);
    engine = NULL;
}

void enter_engine_loop(FieldEngine* engine) {
    SDL_Event e;
    SDL_zero(e);

    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        //Default fill background
        SDL_FillSurfaceRect(engine->mainSurface,
        NULL,
        SDL_MapSurfaceRGB(engine->mainSurface, 100, 100, 100) 
    );


        engine->loopFunction();

        SDL_UpdateWindowSurface(engine->window);
    }
}