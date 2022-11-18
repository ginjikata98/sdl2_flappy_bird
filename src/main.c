
#include "game.h"

game *g_game = 0;

int main(int argc, char *argv[]) {

  g_game = gameNew();

  gameInit(g_game, "Chapter 1", 100, 100, 640, 580, true);

  while (gameIsRunning(g_game)) {
    gameHandleEvents(g_game);
    gameUpdate(g_game);
    gameRender(g_game);
  }
  gameClean(g_game);
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