//
// Created by DUNG.VM on 17/11/2022.
//

#include "draw.h"

void prepareScene(App *app) {
  SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);
  SDL_RenderClear(app->renderer);
}

void presentScene(App *app) {
  SDL_RenderPresent(app->renderer);
}