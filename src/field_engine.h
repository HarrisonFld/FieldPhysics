#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

#include "module.h"


/*
* Engine Core
*/
typedef struct FieldEngine {
    SDL_Window* window;
    SDL_Surface* mainSurface;
    void (*loopFunction)();
    Module* modules;
} FieldEngine;

FieldEngine* create_engine(int screenWidth, int screenHeight, void (*loopFunction)());
void exit_engine(FieldEngine* engine);
void enter_engine_loop(FieldEngine* engine);
void engine_add_module(FieldEngine* engine, Module module);
void engine_add_modules(FieldEngine* engine, int amount, Module module,...);