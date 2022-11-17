//
// Created by DUNG.VM on 17/11/2022.
//

#include "SDL.h"

#ifndef FLAPPY_BIRD_STRUCTS_H
#define FLAPPY_BIRD_STRUCTS_H

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
  SDL_Texture *background;
} App;

#endif //FLAPPY_BIRD_STRUCTS_H
