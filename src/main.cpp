#include "main.hpp"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_video.h>
#include <iostream>

constexpr int kScreenWidth{ 640 };
constexpr int kScreenHeight{ 480 };

/* Global Variables */
//The window we'll be rendering to
SDL_Window* gWindow{ nullptr };
    
//The surface contained by the window
SDL_Surface* gScreenSurface{ nullptr };

//The image we will load and show on the screen
SDL_Surface* gHelloWorld{ nullptr };


//Starts up SDL and creates window
bool init() {
    bool success{true};

    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_Log("SDL could not init! SDL error: %s\n", SDL_GetError());
        success = false;
    } else {
        gWindow = SDL_CreateWindow("Field Physics Attempt", kScreenWidth, kScreenHeight, 0);
        if (gWindow == nullptr) {
            SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError());
            success = false;
        } else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    
    return success;
}

//Loads media
bool loadMedia() {
    return true;
}

//Frees media and shuts down SDL
void close() { 
    //Clean up surface
    SDL_DestroySurface( gHelloWorld );
    gHelloWorld = nullptr;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gScreenSurface = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}


int main() {
    //Final exit code
    int exitCode{0};
    SDL_Log("Starting FieldPhysics");
    //Initialize
    if (init() == false) {
        SDL_Log( "Unable to initialize program!\n" );
        exitCode = 1;
    } else {
        //Load media
        if ( loadMedia() == false ) {
            SDL_Log( "Unable to load media!\n" );
            exitCode = 2;
        } else {
            //The quit flag
            bool quit{ false };

            //The event data
            SDL_Event e;
            SDL_zero( e );

            while(quit == false) {
                //Get event data
                while(SDL_PollEvent( &e ) == true) {
                    //If event is quit type
                    if( e.type == SDL_EVENT_QUIT )
                    {
                        //End the main loop
                        quit = true;
                    }
                }

                //Fill the surface white
                SDL_FillSurfaceRect( gScreenSurface, nullptr, SDL_MapSurfaceRGB( gScreenSurface, 50, 200, 70 ) );
            
                //Render image on screen
                SDL_BlitSurface( gHelloWorld, nullptr, gScreenSurface, nullptr );

                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
            }
        }

        close();
        return exitCode;
    }

    
}
