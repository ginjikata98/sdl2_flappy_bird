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

  SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", path);

  texture->texture = IMG_LoadTexture(renderer, path);
  return texture;
}

void Texture_render(Texture *texture, SDL_Renderer *renderer, int x, int y) {
  SDL_Rect dest;
  dest.x = x;
  dest.y = y;
  dest.w = texture->width;
  dest.h = texture->height;
  SDL_QueryTexture(texture->texture, NULL, NULL, &dest.w, &dest.h);
  SDL_RenderCopy(renderer, texture->texture, NULL, &dest);
}

