#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "boolean.h"

#include "sheet.h"
#include "sprite.h"
#include "map.h"

typedef struct {
	sheet_t *sheet;
	sprite_t *sprite;
	map_t *map;

	int x, y;
} player_t;

extern player_t *PL_Create(sheet_t *, map_t *);
extern void PL_Destroy(player_t *p);

extern boolean PL_Move(player_t *, int, int);
extern void PL_Handle(player_t *, SDL_Event);
extern void PL_Draw(player_t *);

#endif /* PLAYER_H */
