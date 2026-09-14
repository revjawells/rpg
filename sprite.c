#include <stdlib.h>
#include <SDL2/SDL.h>

#include "iface.h"
#include "sprite.h"
#include "point.h"
#include "error.h"

sprite *SP_Create(const char *file, int x, int y)
{
	sprite *s;
	int w, h;

	s = (sprite *) emalloc(sizeof (sprite));
	s->pos = (SDL_Rect *) emalloc(sizeof (SDL_Rect));

	s->t = IF_Load(file);
	s->pos->x = x;
	s->pos->y = y;

	SDL_QueryTexture(s->t, NULL, NULL, &w, &h);
	s->pos->w = w;
	s->pos->h = h;

	return s;
}

void SP_Update(sprite *s, point *p)
{
	s->pos->x = p->x;
	s->pos->y = p->y;
}

boolean SP_IsTouching(sprite *s, sprite *t)
{
/*
	SDL_Rect a, b;

	a.x = s->pos.x;
	a.y = s->pos.y;
	SDL_QueryTexture(s->t, NULL, NULL, &a.w, &a.h);

	b.x = t->pos.x;
	b.y = t->pos.y;
	SDL_QueryTexture(t->t, NULL, NULL, &b.w, &b.h);

	return SDL_HasIntersection(&a, &b);
*/
	return FALSE;
}

void SP_Destroy(sprite *s)
{
	SDL_DestroyTexture(s->t);
	free(s->pos);
	free(s);
}
