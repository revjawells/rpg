#include <stdio.h>
#include <SDL2/SDL.h>

#include "error.h"

#define TRY(x)	if((x) == NULL) error(SDL_GetError())
#define VTRY(x,y)	if((x) != (y)) error(SDL_GetError())

void error(const char *msg)
{
   fprintf(stderr, "%s\n", msg);
   SDL_Quit();
   exit(1);
}
