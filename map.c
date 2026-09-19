#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "error.h"

#include "map.h"
#include "player.h"

#include "iface.h"
#include "sheet.h"
#include "sprite.h"

#include "tiledata.h"

extern const tiledata_ent tiledata[];

/* not robust - add error checking */
map_t *MP_Create(const char *file, sheet_t *sprites)
{
	char buffer[BUFSIZE];

	map_t *m = (map_t *) emalloc(sizeof(map_t));

	m->sprites = sprites;

	/* open file */
	FILE *fp = fopen(file, "r");
	if (fp == NULL)
		error("MP_Create: fopen failed\n");

	/* read size */
	fgets(buffer, BUFSIZE, fp);
	m->size = atoi(buffer);

	/* allocate arrays */
	int **a = (int **) emalloc(m->size * sizeof(int *));
	for (int i = 0; i < m->size; i++)
		a[i] = (int *) emalloc(m->size * sizeof(int));

	m->tiles = a;

	/* read map data */
	int i = 0;
	while (fgets(buffer, BUFSIZE, fp)) {
		char *token = strtok(buffer, ",");
		int j = 0;
		
		while (token) {
			m->tiles[i][j] = atoi(token);	
			token = strtok(NULL, ",");
			j += 1;
		}

		i += 1;
	}

	/* close file */
	fclose(fp);

	return m;
}

void MP_Destroy(map_t *m)
{
	for (int i = 0; i < m->size; i++)
		free(m->tiles[i]);

	free(m->tiles);
	free(m);
}

/* draw map centered around point */
void MP_Draw(map_t *m, int px, int py)
{
	sprite_t *sp = SP_Create(m->sprites, 0, 0, 0);

	for (sp->y = 0; sp->y < WINSIZE; sp->y++) {
		int i = sp->y + py - (WINSIZE / 2);

		for (sp->x = 0; sp->x < WINSIZE; sp->x++) {
			int j = sp->x + px - (WINSIZE / 2);

			if (MP_IsInBounds(m, i, j)) {
				sp->tile = tiledata[m->tiles[i][j]].tile;
				SP_Draw(sp);
			} else {
				// draw nothing
			}
		}
	}
}

boolean MP_IsInBounds(map_t *m, int x, int y)
{
	if (m != NULL) 
		return (x >= 0 && x < m->size
				&& y >= 0 && y < m->size);
	else
		return FALSE;
}
