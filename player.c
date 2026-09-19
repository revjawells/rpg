#include <SDL2/SDL.h>

#include "player.h"

#include "sheet.h"
#include "sprite.h"
#include "map.h"

#include "boolean.h"
#include "config.h"
#include "error.h"

player_t *PL_Create(sheet_t *sh, map_t *m)
{
	player_t *p = (player_t *) emalloc(sizeof(player_t));

	p->sheet = sh;
	p->map = m;

	p->x = p->y = (MAPSIZE / 2) - 1;
	p->sprite = SP_Create(sh, 25, WINSIZE / 2, WINSIZE / 2);

	return p;
}

void PL_Destroy (player_t *p)
{
	free(p);
}

boolean PL_Move(player_t *p, int dx, int dy)
{
	int nx = p->x + dx;
	int ny = p->y + dy;

	if (nx >= 0 && nx < MAPSIZE && ny >= 0 && ny < MAPSIZE) {
		p->x = nx;
		p->y = ny;
		return TRUE;
	}

	return FALSE;
}

void PL_Handle(player_t *p, SDL_Event e)
{
	int result;

	switch(e.key.keysym.sym) {
		case DO_LEFT:
			result = PL_Move(p, -1, 0);
			break;

		case DO_RIGHT:
			result = PL_Move(p, +1, 0);
			break;

		case DO_UP:
			result = PL_Move(p, 0, -1);
			break;

		case DO_DOWN:
			result = PL_Move(p, 0, +1);
			break;

		case DO_START:
			p->x = p->y = MAPSIZE / 2;
			break;

		case DO_A:
		case DO_B:
		case DO_SELECT:
		default:
			break;
	}

	if (!result) {
		// BLOCKED
	}
}

void PL_Draw(player_t *p)
{
	SP_Draw(p->sprite);
}
