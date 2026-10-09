#include <SDL2/SDL.h>

#include "player.h"

#include "sheet.h"
#include "sprite.h"
#include "map.h"

#include "boolean.h"
#include "config.h"
#include "error.h"

#include "tiledata.h"
#include "mode.h"

extern tiledata_ent tiledata[];

player_t *PL_Create(const char *name, sheet_t *sh, map_t *m)
{
	player_t *p = (player_t *) emalloc(sizeof(player_t));

	p->sheet = sh;
	p->map = m;

	p->mode = WALKABOUT;

	/* command cursor position */
	p->cx = p->cy = 0;

	p->x = 1;
	p->y = 15;
	p->sprite = SP_Create(sh, 25, WINSIZE / 2, WINSIZE / 2);

	p->name = estrdup(name);

	p->level = 1;
	p->hp = p-> hpmax = 15;
	p->mp = p-> mpmax = 0;
	p->gold = 0;
	p->xp = 0;

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

	if (p->mode == COMMAND) {
		nx = p->cx + dx;
		ny = p->cy + dy;

		if (nx >= 0 && nx < 2 && ny >= 0 && ny < 4) {
			p->cx = nx;
			p->cy = ny;
		}

		return FALSE;
	} else {
		/* p->mode == WALKABOUT */

    	if (MP_IsInBounds(p->map, nx, ny)
    		&& tiledata[p->map->tiles[ny][nx]].flags == PASSABLE) {
    		p->x = nx;
    		p->y = ny;
    
#ifdef DEBUG
    		int x = p->map->tiles[ny][nx];
    		printf("TILE #%d\t#%d\n", x, tiledata[x].tile);
#endif
    
    		return TRUE;
    	}
		return FALSE;
	}

	return FALSE;
}

boolean PL_Handle(player_t *p, SDL_Event e)
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

		case DO_A:
			if (p->mode == WALKABOUT) {
			    p->mode = COMMAND;
			    p->cx = p->cy = 0;
			} else {
				/* dispatch command */

#ifdef DEBUG
				printf("COMMAND: %d %d\n", p->cx, p->cy);	
#endif
			}

			break;

		case DO_B:
			p->mode = WALKABOUT;
			break;

		case DO_START:
		case DO_SELECT:
		default:
			break;
	}

	if (!result) {
		// BLOCKED
	}

	return result;
}

void PL_Draw(player_t *p)
{
	SP_Draw(p->sprite);
}
