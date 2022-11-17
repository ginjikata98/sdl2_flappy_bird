//
// Created by DUNG.VM on 17/11/2022.
//

#include "input.h"

void handleInput(void) {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        exit(0);

      case SDL_KEYDOWN:
        printf("%d", event.key.keysym.scancode);
        break;

      default:
        break;
    }
  }
}
