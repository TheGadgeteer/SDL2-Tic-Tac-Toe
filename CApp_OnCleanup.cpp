//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnCleanup() {
    if (this->Renderer) {
        SDL_DestroyRenderer(Renderer);
        Renderer = NULL;
    }
    SDL_FreeSurface(Surf_Grid);
    SDL_FreeSurface(Surf_X);
    SDL_FreeSurface(Surf_O);
    SDL_FreeSurface(Surf_PrimarySurface);

    if (Win_Window) {
        SDL_DestroyWindow(Win_Window);
        Win_Window = NULL;
    }

    SDL_Quit();
}

//==============================================================================
