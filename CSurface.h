//==============================================================================
// Surface functions
//==============================================================================
#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL2/SDL.h>

//==============================================================================
class CSurface {
	public:
		CSurface();

	public:
		static SDL_Texture* OnLoad(SDL_Renderer* Renderer, const char* File);
		static SDL_Texture* OnLoadTransparent(SDL_Renderer* Renderer, const char* File, int R, int G, int B);

		static bool OnDraw(SDL_Renderer* ren, SDL_Texture* tex, int X, int Y);

		static bool OnDraw(SDL_Renderer* ren, SDL_Texture* tex, int X, int Y, int X2, int Y2, int W, int H);

		static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

//==============================================================================

#endif
