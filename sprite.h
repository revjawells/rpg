#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"

#include "sheet.h"

typedef struct {
	sheet_t *sheet;
	int tile;

	int x, y;
} sprite_t;

extern sprite_t *SP_Create(sheet_t *, int, int, int);
extern void SP_Draw(sprite_t *);
extern void SP_Destroy(sprite_t *);

#endif /* SPRITE_H */
