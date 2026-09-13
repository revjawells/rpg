#ifndef ERROR_H
#define ERROR_H

#define TRY(x)	if((x) == NULL) error(SDL_GetError())
#define VTRY(x,y)	if((x) != (y)) error(SDL_GetError())

extern void error(const char *);

#endif
