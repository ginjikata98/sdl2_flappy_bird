//
// Created by DUNG.VM on 17/11/2022.
//

#include "init.h"
#include "defs.h"
#include "SDL_image.h"

SDL_Texture *loadTexture(App *app, char *path) {
  SDL_Texture *newTexture = NULL;

  SDL_Surface *loadedSurface = IMG_Load(path);
  if (loadedSurface == NULL) {
    printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
  } else {
    newTexture = SDL_CreateTextureFromSurface(app->renderer, loadedSurface);
    if (newTexture == NULL) {
      printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
    }

    SDL_FreeSurface(loadedSurface);
  }

  return newTexture;
}


App initSDL(void) {
  App app;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }

  app.window = SDL_CreateWindow("Shooter 01",
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (!app.window) {
    printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
    exit(1);
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);

  if (!app.renderer) {
    printf("Failed to create renderer: %s\n", SDL_GetError());
    exit(1);
  }


  if (IMG_Init(IMG_INIT_PNG) == 0) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    exit(1);
  }

  app.background = loadTexture(&app, "assets/bg.png");

  return app;
}
