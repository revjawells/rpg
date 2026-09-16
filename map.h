#ifndef MAP_H
#define MAP_H

#include "config.h"
#include "sheet.h"

typedef struct {
	int **tiles;
	int size;
	sheet *sprites;
} map;

extern map *MP_Create(const char *, sheet *);
extern void MP_Destroy(map *);

extern void MP_Draw(map *);

#endif /* MAP_H */
