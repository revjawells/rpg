#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"

#include "point.h"
#include "boolean.h"

typedef struct {
	SDL_Texture *t;
	SDL_Rect *pos;
} sprite;

extern sprite *SP_Create(const char *, int, int);
extern void SP_Update(sprite *, point *);
extern void SP_Destroy(sprite *);
extern boolean SP_IsTouching(sprite *, sprite *);

#endif /* SPRITE_H */
