#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "structs.h"
#include "init.h"
#include "draw.h"
#include "input.h"


int main(int argc, char *argv[]) {
  App *app = initSDL();

//  atexit(cleanup);

  while (true) {
    prepareScene(app);

    handleInput();

    presentScene(app);

    SDL_Delay(16);
  }

  return 0;
}