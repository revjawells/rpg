#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "sheet.h"
#include "map.h"
#include "sprite.h"
#include "boolean.h"

typedef struct {
	sheet *sh;
	sprite *sp;
	map *m;

	int x, y;

} player;

extern player *PL_Create(sheet *, map *);
extern void PL_Destroy(player *p);

extern boolean PL_Move(player *, int, int);
extern void PL_Handle(player *, SDL_Event);
extern void PL_Draw(player *);

#endif /* PLAYER_H */
