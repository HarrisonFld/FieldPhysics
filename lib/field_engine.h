#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

typedef struct FieldEngine {
    SDL_Window* window;
    SDL_Surface* mainSurface;
    void (*loopFunction)();
} FieldEngine;

FieldEngine* create_engine(int screenWidth, int screenHeight, void (*loopFunction)());
void exit_engine(FieldEngine* engine);
void enter_engine_loop(FieldEngine* engine);