//==============================================================================
#include "CApp.h"
//==============================================================================
bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Win_Window = SDL_CreateWindow("Tic-Tac-Toe Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            600, 600, SDL_WINDOW_SHOWN)) == NULL) {
        return false;
    }

    if ((Renderer = SDL_CreateRenderer(Win_Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        return false;
    }

    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);

    if((tex_Grid = CSurface::OnLoad(Renderer, "./gfx/grid.bmp")) == NULL) {
        return false;
    }

    if((tex_X = CSurface::OnLoadTransparent(Renderer, "./gfx/x.bmp", 255, 0, 255)) == NULL) {
        return false;
    }

    if((tex_O = CSurface::OnLoadTransparent(Renderer, "./gfx/o.bmp", 255, 0, 255)) == NULL) {
        return false;
    }

    Reset();

    return true;
}

//==============================================================================
