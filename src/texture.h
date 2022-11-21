//
// Created by DUNG.VM on 17/11/2022.
//

#ifndef FLAPPY_BIRD_TEXTURE_H
#define FLAPPY_BIRD_TEXTURE_H

#include "SDL2/SDL.h"

typedef struct Texture {
  SDL_Texture *texture;
  int width;
  int height;
} Texture;

Texture *Texture_init();

void Texture_destroy(Texture *texture);

Texture *Texture_loadFromFile(SDL_Renderer *renderer, char *path);

void Texture_render(Texture *texture, SDL_Renderer *renderer, int x, int y);

#endif //FLAPPY_BIRD_TEXTURE_H
