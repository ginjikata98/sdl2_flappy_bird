//
// Created by DUNG.VM on 18/11/2022.
//

#include "game.h"


struct Game {
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool running;
  SDL_Texture *texture;
  SDL_Rect srcRect; // the first rectangle
  SDL_Rect destRect; // another rectangle
};

Game *gameNew(void) {
  Game *g = malloc(sizeof(Game));
  g->running = false;
  return g;
}

bool gameInit(Game *g, const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR,
                   "Couldn't initialize SDL: %s",
                   SDL_GetError());
    return false;
  }

  int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
  g->window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);

  if (!g->window) {
    SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR,
                   "Failed to open %d x %d window: %s",
                   width, height, SDL_GetError());

    return false;
  }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  g->renderer = SDL_CreateRenderer(g->window, -1, SDL_RENDERER_ACCELERATED);

  if (!g->renderer) {
    SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR,
                   "Failed to create renderer: %s",
                   SDL_GetError());
    return false;
  }

  SDL_SetRenderDrawColor(g->renderer, 0, 0, 0, 0);


  if (IMG_Init(IMG_INIT_PNG) == 0) {
    SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_ERROR,
                   "SDL_image could not initialize! SDL_image Error: %s",
                   IMG_GetError());
    return false;
  }

  g->texture = IMG_LoadTexture(g->renderer, "assets/platform/char9.png");
  g->srcRect.x = 0;
  g->srcRect.y = 0;
  g->srcRect.w = 128;
  g->srcRect.h = 200;
  g->destRect.x = 0;
  g->destRect.y = 0;
  g->destRect.w = g->srcRect.w;
  g->destRect.h = g->srcRect.h;

  g->running = true;
  return true;
}

void gameRender(Game *g) {
  SDL_RenderClear(g->renderer);

  SDL_RenderCopy(g->renderer, g->texture, &g->srcRect, &g->destRect);

  SDL_RenderPresent(g->renderer);
}


void gameClean(Game *g) {
  SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                 "Cleaning Game...");
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
  int frame = (int) ((SDL_GetTicks() / 100) % 6);
  g->srcRect.x = 128 * (frame % 4);
//  g->srcRect.y = 200 * (frame / 4);
}