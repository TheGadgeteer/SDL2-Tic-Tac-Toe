//==============================================================================
#include "CSurface.h"

//==============================================================================
CSurface::CSurface() {
}

//==============================================================================
SDL_Texture* CSurface::OnLoad(SDL_Renderer* Renderer, const char* File) {
	SDL_Surface* Surf_Temp = NULL;

	if((Surf_Temp = SDL_LoadBMP(File)) == NULL) {
		return NULL;
	}

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer, Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

	return texture;
}

SDL_Texture* CSurface::OnLoadTransparent(SDL_Renderer* Renderer, const char* File, int R, int G, int B) {
	SDL_Surface* Surf_Temp = NULL;

	if((Surf_Temp = SDL_LoadBMP(File)) == NULL) {
		return NULL;
	}

	// make transparent
    SDL_SetColorKey(Surf_Temp, SDL_TRUE, SDL_MapRGB(Surf_Temp->format, R, G, B));

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer, Surf_Temp);
    SDL_FreeSurface(Surf_Temp);

	return texture;
}

//==============================================================================
bool CSurface::OnDraw(SDL_Renderer* ren, SDL_Texture* tex, int X, int Y) {
	if(ren == NULL || tex == NULL) {
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_QueryTexture(tex, NULL, NULL, &DestR.w, &DestR.h);
    SDL_RenderCopy(ren, tex, NULL, &DestR);
	return true;
}

//------------------------------------------------------------------------------
bool CSurface::OnDraw(SDL_Renderer* ren, SDL_Texture* tex, int X, int Y, int X2, int Y2, int W, int H) {
	if(ren == NULL || tex == NULL) {
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

    SDL_QueryTexture(tex, NULL, NULL, &DestR.w, &DestR.h);
    SDL_RenderCopy(ren, tex, &SrcR, &DestR);

	return true;
}

