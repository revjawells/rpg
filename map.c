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

	for (int row = -WINSIZE / 2; row < WINSIZE / 2; row++) {
		sp->x = row + px;

		for (int col = -WINSIZE / 2; col < WINSIZE / 2; col++) {
			sp->y = col + py;
			sp->tile = m->tiles[sp->y][sp->x];
			SP_Draw(sp);
		}
	}

/*
 * OLD - draws entire map
 *
	for (int row = 0; row < m->size; row++) {
		sp->x = row;

		for (int col = 0; col < m->size; col++) {
			sp->tile = m->tiles[col][row];		
			sp->y = col;
			SP_Draw(sp);
		}
	}
*/
}
