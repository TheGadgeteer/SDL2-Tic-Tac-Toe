//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {
	//CSurface::OnDraw(Win_Window, Surf_Grid, 0, 0);

    for(int i = 0;i < 9;i++) {
        int X = (i % 3) * 200;
        int Y = (i / 3) * 200;

        if(Grid[i] == GRID_TYPE_X) {
//            CSurface::OnDraw(Win_Window, Surf_X, X, Y);
        }else
        if(Grid[i] == GRID_TYPE_O) {
  //          CSurface::OnDraw(Win_Window, Surf_O, X, Y);
        }
    }

//	SDL_Flip(Surf_Display);
}

//==============================================================================
