//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnCleanup() {
    if (this->Renderer) {
        SDL_DestroyRenderer(Renderer);
        Renderer = NULL;
    }

    if (Win_Window) {
        SDL_DestroyWindow(Win_Window);
        Win_Window = NULL;
    }

    SDL_Quit();
}

//==============================================================================
