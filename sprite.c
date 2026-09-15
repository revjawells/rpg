#include <stdlib.h>
#include <SDL2/SDL.h>

#include "config.h"

#include "iface.h"
#include "sheet.h"
#include "sprite.h"
#include "error.h"

sprite *SP_Create(sheet *sh, int tile, int x, int y)
{
	sprite *s;

	s = (sprite *) emalloc(sizeof (sprite));

	s->sh = sh;
	s->tile = tile;
	s->x = x;
	s->y = y;

	return s;
}

void SP_Draw(sprite *s)
{
	IF_Draw(s, s->x * TILESIZE, s->y * TILESIZE);
}

void SP_Destroy(sprite *s)
{
	free(s);
}
