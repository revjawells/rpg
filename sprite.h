#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"

#include "sheet.h"

typedef struct {
	sheet *sh;
	int tile;

	int x, y;
} sprite;

extern sprite *SP_Create(sheet *, int, int, int);
extern void SP_Draw(sprite *);
extern void SP_Destroy(sprite *);

#endif /* SPRITE_H */
