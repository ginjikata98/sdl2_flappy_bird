//
// Created by DUNG.VM on 17/11/2022.
//


#ifndef FLAPPY_BIRD_STRUCTS_H
#define FLAPPY_BIRD_STRUCTS_H

#include "SDL.h"
#include "texture.h"

typedef struct App {
  SDL_Renderer *renderer;
  SDL_Window *window;
  Texture *background;
} App;

#endif //FLAPPY_BIRD_STRUCTS_H
