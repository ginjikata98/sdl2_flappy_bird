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
#include "structs.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include <stdbool.h>

typedef struct Game game;

game *gameNew(void);

void gameFree(game *g);

bool gameInit(game *g, const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen);

void gameRender(game *g);

void gameUpdate(game *g);

void gameHandleEvents(game *g);

void gameClean(game *g);

bool gameIsRunning(game *g);


#endif //FLAPPY_BIRD_GAME_H
