#include <stdlib.h>
#include <SDL2/SDL.h>

#include "config.h"

#include "iface.h"
#include "sheet.h"
#include "sprite.h"
#include "error.h"

sprite_t *SP_Create(sheet_t *sh, int tile, int x, int y)
{
	sprite_t *s;

	s = (sprite_t *) emalloc(sizeof (sprite_t));

	s->sheet = sh;
	s->tile = tile;
	s->x = x;
	s->y = y;

	return s;
}

void SP_Draw(sprite_t *s)
{
	IF_Draw(s, s->x, s->y);
}

void SP_Destroy(sprite_t *s)
{
	free(s);
}
