//
// Created by DUNG.VM on 18/11/2022.
//

#ifndef FLAPPY_BIRD_GAME_H
#define FLAPPY_BIRD_GAME_H

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

typedef struct Game Game;

Game *GameNew(void);

bool GameInit(Game *g, const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen);

void GameRender(Game *g);

void GameUpdate(Game *g);

void GameHandleEvents(Game *g);

void GameClean(Game *g);

bool GameIsRunning(Game *g);


#endif //FLAPPY_BIRD_GAME_H
