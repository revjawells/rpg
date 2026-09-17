#include "config.h"

#include "iface.h"
#include "boolean.h"
#include "sheet.h"
#include "sprite.h"

#include "map.h"
#include "player.h"

/* game variables */
sheet	*sprites;
player	*hero;
map		*hut;

void setup(void)
{
	IF_Create();

	sprites = SH_Create("assets/tiles.png", TILESIZE, TILESIZE);
	hut = MP_Create("hut.map", sprites);
	hero = PL_Create(sprites, hut);
}

void cleanup(void)
{
	PL_Destroy(hero);
	MP_Destroy(hut);
	SH_Destroy(sprites);
	IF_Destroy();
}

int main(int argc, char **argv)
{
	boolean quit = FALSE;

	setup();
	atexit(cleanup);

	while (!quit) {
		SDL_Event e;

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = TRUE;
			} else if (e.type == SDL_KEYDOWN) {
				PL_Handle(hero, e);
			}
		} 
	
		IF_Clear();

		MP_Draw(hut);
		PL_Draw(hero);

		IF_Render();
	} 

	return 0;
}
