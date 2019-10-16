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

    Surf_PrimarySurface = SDL_GetWindowSurface(Win_Window);

    if ((Renderer = SDL_CreateRenderer(Win_Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        return false;
    }

    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);

    if((Surf_Grid = CSurface::OnLoad("./gfx/grid.bmp")) == NULL) {
        return false;
    }

    if((Surf_X = CSurface::OnLoad("./gfx/x.bmp")) == NULL) {
        return false;
    }

    if((Surf_O = CSurface::OnLoad("./gfx/o.bmp")) == NULL) {
        return false;
    }

    CSurface::Transparent(Surf_X, 255, 0, 255);
    CSurface::Transparent(Surf_O, 255, 0, 255);

    Reset();

    return true;
}

//==============================================================================
