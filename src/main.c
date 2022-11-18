#include "game.h"

Game *game = 0;

int main(int argc, char *argv[]) {

  game = gameNew();

  gameInit(game, "Chapter 1", 100, 100, 640, 580, false);

  while (gameIsRunning(game)) {
    gameHandleEvents(game);
    gameUpdate(game);
    gameRender(game);
  }
  gameClean(game);
  return 0;
}

//int main(int argc, char *argv[]) {
//  App *app = initSDL();
//
////  atexit(cleanup);
//
//  while (true) {
//    prepareScene(app);
//
//    handleInput();
//
//    presentScene(app);
//
//    SDL_Delay(16);
//  }
//
//  return 0;
//}