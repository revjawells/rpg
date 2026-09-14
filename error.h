#ifndef ERROR_H
#define ERROR_H

#include <stddef.h>

#define TRY(x)	if((x) == NULL) error(SDL_GetError())
#define VTRY(x,y)	if((x) != (y)) error(SDL_GetError())

extern void error(const char *);
extern void *emalloc(size_t);

#endif
