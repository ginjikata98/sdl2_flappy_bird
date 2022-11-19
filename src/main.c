#include "game.h"

int main(int argc, char *argv[]) {
  Game *game = GameNew();

  GameInit(game, "Chapter 1", 100, 100, 640, 580, false);

  while (GameIsRunning(game)) {
    GameHandleEvents(game);
    GameUpdate(game);
    GameRender(game);
  }
  GameClean(game);
  return 0;
}