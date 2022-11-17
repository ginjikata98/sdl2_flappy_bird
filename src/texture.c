//
// Created by DUNG.VM on 17/11/2022.
//

#include "texture.h"
#include "SDL_image.h"


Texture *Texture_init() {
  Texture *texture = malloc(sizeof(Texture));
  texture->width = 0;
  texture->height = 0;
  texture->texture = NULL;
  return texture;
}

void Texture_destroy(Texture *texture) {
  if (texture != NULL) {
    if (texture->texture != NULL) {
      free(texture->texture);
    }
    free(texture);
  }
}

Texture *Texture_loadFromFile(SDL_Renderer *renderer, char *path) {
  Texture *texture = Texture_init();
  SDL_Texture *newTexture = NULL;

  SDL_Surface *loadedSurface = IMG_Load(path);
  if (loadedSurface == NULL) {
    printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
  } else {
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL) {
      printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
    }

    SDL_FreeSurface(loadedSurface);
  }

  texture->texture = newTexture;

  return texture;
}
