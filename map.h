#ifndef MAP_H
#define MAP_H

#include "config.h"
#include "sheet.h"

typedef struct {
	int	**tiles;
	int	size;
	sheet_t	*sprites;
} map_t;

extern map_t *MP_Create(const char *, sheet_t *);
extern void MP_Destroy(map_t *);

extern void MP_Draw(map_t *, int, int);

#endif /* MAP_H */
