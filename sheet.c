#include <stdlib.h>
#include <SDL2/SDL.h>

#include "config.h"

#include "iface.h"
#include "sheet.h"
#include "error.h"

/* SH_Create - give a file name and the size of a tile */
sheet *SH_Create(const char *file, int w, int h)
{
	sheet *s;

	s = (sheet *) emalloc(sizeof (sheet));

	s->t = IF_Load(file);
	s->twidth = w;
	s->theight = h;

	SDL_QueryTexture(s->t, NULL, NULL,
						&s->swidth, &s->sheight);

	return s;
}

void SH_Destroy(sheet *s)
{
	SDL_DestroyTexture(s->t);
	free(s);
}
