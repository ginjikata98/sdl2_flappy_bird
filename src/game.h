//
// Created by DUNG.VM on 18/11/2022.
//

#ifndef FLAPPY_BIRD_GAME_H
#define FLAPPY_BIRD_GAME_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

typedef struct Game Game;

Game *gameNew(void);

bool gameInit(Game *g, const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen);

void gameRender(Game *g);

void gameUpdate(Game *g);

void gameHandleEvents(Game *g);

void gameClean(Game *g);

bool gameIsRunning(Game *g);


#endif //FLAPPY_BIRD_GAME_H
