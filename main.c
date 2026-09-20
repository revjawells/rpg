#include "config.h"
#include "error.h"

#include "iface.h"
#include "boolean.h"
#include "sheet.h"
#include "sprite.h"

#include "player.h"
#include "map.h"

/* game variables */
sheet_t		*sprites;
player_t	*hero;
map_t		*map;

void setup(char *name)
{
	setprogname(name);

	IF_Create();

	sprites = SH_Create("assets/tiles.png", TILESIZE, TILESIZE);
	map = MP_Create("assets/town.map", sprites);
	hero = PL_Create(sprites, map);
}

void cleanup(void)
{
	PL_Destroy(hero);
	MP_Destroy(map);
	SH_Destroy(sprites);
	IF_Destroy();
}

int main(int argc, char **argv)
{
	boolean quit = FALSE;

	setup(argv[0]);
	atexit(cleanup);

	while (!quit) {
		SDL_Event e;
		boolean dirty;

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = TRUE;
			} else if (e.type == SDL_KEYDOWN) {
				dirty = PL_Handle(hero, e);
			}
		} 
	
		if (dirty) {
		IF_Clear();

		MP_Draw(map, hero->x, hero->y);
		PL_Draw(hero);

		IF_Render();
		}
	} 

	return 0;
}
