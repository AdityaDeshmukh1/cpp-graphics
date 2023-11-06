#include <SDL2/SDL.h>
#include <vector>

int main(){

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(640, 480, 0, &window,
		&renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	std::vector<SDL_Point> v;
	std::vector<SDL_Rect> rv;

	for (int i = 0; i < 100; i++){
		v.emplace_back(rand()%640, rand()%480);
		rv.emplace_back(rand()%640, rand()%480, 40, 20);
	}

	SDL_RenderDrawPoints(renderer, v.data(), v.size());
	SDL_RenderDrawLines(renderer, v.data(), v.size()); 
	SDL_RenderDrawRects(renderer, rv.data(), rv.size());
	SDL_RenderFillRects(renderer, rv.data(), rv.size());

	SDL_RenderPresent(renderer);
	SDL_Delay(10000);
 

	return 0;

}