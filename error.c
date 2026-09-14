#include <stdio.h>
#include <stddef.h>

#include <SDL2/SDL.h>

#include "error.h"

#define TRY(x)	if((x) == NULL) error(SDL_GetError())
#define VTRY(x,y)	if((x) != (y)) error(SDL_GetError())

void error(const char *msg)
{
   fprintf(stderr, "%s\n", msg);
   exit(1);
}

void *emalloc(size_t n)
{
	void *p;

	p = malloc (n);
	if (p == NULL) 
		error("emalloc failed");

	return p;
}
