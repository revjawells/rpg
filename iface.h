#ifndef IFACE_H
#define IFACE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "error.h"
#include "sprite.h"

extern void IF_Create(void);
extern void IF_Destroy(void);

extern void IF_Clear(void);
extern void IF_Render(void);

extern SDL_Texture *IF_Load(const char *);
extern void IF_Draw(sprite *s, int, int);

#endif
