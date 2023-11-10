#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <numeric>
#include <complex>

int isInSet(std::complex<double> c){
    std::complex<double> z(0, 0);
    for(int i = 0; i < 250; i++){

        z = std::pow(z ,2) + c;
        if (std::norm(z) > 10){
            return i;
        }
    }
    return 0;
}

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(1000, 1000, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);

    for(double i = 0.0; i < 1.0; i +=0.01){
        for(double j = 0.0; j < 1.0; j +=0.01){
            double point_x = std::lerp(-2.0, 2.0, i);
            double point_y = std::lerp(-2.0, 2.0, j);
            int iters = isInSet(std::complex<double>(i, j));
            if (iters == 0) {
                SDL_SetRenderDrawColor(renderer,0,0,0, 255);
                SDL_RenderDrawPointF(renderer, i*1000, j*1000);
            }
            else {
                SDL_SetRenderDrawColor(renderer,
                 12 * iters % 255,
                  13 * iters % 255,
                   14 * iters % 255,
                    255);
                SDL_RenderDrawPointF(renderer, i*1000, j*1000);
            }
        }
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);



}