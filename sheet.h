#ifndef SHEET_H
#define SHEET_H

#include "SDL2/SDL.h"

#include "boolean.h"

typedef struct {
	SDL_Texture *t;

	/* sheet size */
	int swidth, sheight;

	/* tile size */
	int twidth, theight;
} sheet;

extern sheet *SH_Create(const char *, int, int);
extern void SH_Destroy(sheet *);

#endif /* SHEET_H */
