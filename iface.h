#ifndef IFACE_H
#define IFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "error.h"
#include "sprite.h"

extern SDL_Renderer *ren;
extern SDL_Texture *img;

extern void IF_Create(void);
extern void IF_Destroy(void);

extern SDL_Texture *IF_Load(const char *);

/*
extern void IF_Scale(SDL_Texture *, SDL_Renderer *, int, int, int, int);
*/

extern void IF_Render(sprite *s);

#endif
