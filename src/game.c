//
// Created by DUNG.VM on 18/11/2022.
//

#include "game.h"


struct Game {
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool running;
};

Game *gameNew(void) {
  Game *g = malloc(sizeof(Game));
  g->running = false;
  return g;
}

bool gameInit(Game *g, const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("Couldn't initialize SDL: %s\n", SDL_GetError());
    return false;
  }

  int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
  g->window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);

  if (!g->window) {
    printf("Failed to open %d x %d window: %s\n", width, height, SDL_GetError());
    return false;
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  g->renderer = SDL_CreateRenderer(g->window, -1, SDL_RENDERER_ACCELERATED);

  if (!g->renderer) {
    printf("Failed to create renderer: %s\n", SDL_GetError());
    return false;
  }

  SDL_SetRenderDrawColor(g->renderer, 255, 255, 255, 255);


  if (IMG_Init(IMG_INIT_PNG) == 0) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    return false;
  }

  g->running = true;
  return true;
}

void gameRender(Game *g) {
  SDL_RenderClear(g->renderer);

  SDL_RenderPresent(g->renderer);
}


void gameClean(Game *g) {
  printf("cleaning Game...\n");
  SDL_DestroyWindow(g->window);
  SDL_DestroyRenderer(g->renderer);
  SDL_Quit();
}

bool gameIsRunning(Game *g) {
  return g->running;
}

void gameHandleEvents(Game *g) {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        g->running = false;
        break;

      default:
        break;
    }
  }
}

void gameUpdate(Game *g) {

}