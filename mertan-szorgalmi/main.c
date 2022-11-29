#include <SDL2/SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("Nem indithato az SDL: %s", SDL_GetError());
		exit(1);
	}
	SDL_Window* window = SDL_CreateWindow("mertan szorgalmi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	if (window == NULL) {
		SDL_Log("Nem hozhato letre az ablak: %s", SDL_GetError());
		exit(1);
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if (renderer == NULL) {
		SDL_Log("Nem hozhato letre a megjelenito: %s", SDL_GetError());
		exit(1);
	}
	SDL_RenderClear(renderer);
	circleRGBA(renderer, 320, 240, 100, 255, 0, 0, 255);
	circleRGBA(renderer, 240, 200, 250, 0, 255, 0, 255);
	circleRGBA(renderer, 400, 280, 100, 0, 250, 0, 255);
	// circleRGBA(renderer, 240, 240, 100, 255, 0, 0, 255);

	SDL_RenderPresent(renderer);

	return 0;
}
