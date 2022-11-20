#include "game.h"

const int FPS = 5;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char *argv[]) {
  Game *game = GameNew();

  GameInit(game, "Chapter 1", 100, 100, 640, 580, false);

  Uint32 frameStart, frameTime;

  while (GameIsRunning(game)) {
    frameStart = SDL_GetTicks();
    GameHandleEvents(game);
    GameUpdate(game);
    GameRender(game);
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < DELAY_TIME) {
      SDL_Delay((int) (DELAY_TIME - frameTime));
    }
  }
  GameClean(game);
  return 0;
}