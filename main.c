#include "config.h"

#include "iface.h"
#include "boolean.h"
#include "sheet.h"
#include "sprite.h"

#include "map.h"

int main(int argc, char **argv)
{
	SDL_Event e;
   
	boolean quit = FALSE;

	sheet *sprites;
	map *hut;
	sprite *hero;
   
	IF_Create();

	sprites = SH_Create("assets/tiles.png", TILESIZE, TILESIZE);
	hut = MP_Create("hut.map", sprites);
	hero = SP_Create(sprites, 25, 3, 3);

	while (!quit) {
		/* get user input */
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = TRUE;
			}
/*
else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
						case DO_UP:
							PL_Update(s, 0, -1);
							break;

						case DO_DOWN:
							PL_Update(s, 0, +1);
							break;

						case DO_LEFT:
							PL_Update(s, -1, 0);
							break;

						case DO_RIGHT:
							PL_Update(s, +1, 0);
							break;

						case DO_START:
						case DO_A:
						case DO_B:
						case DO_SELECT:
							break;

						default: break;
				} 
			}
*/
		} /* while pollevent */
	
		/* draw the map */
		IF_Clear();

		MP_Draw(hut);
		SP_Draw(hero);

		/* render the scene */
		IF_Render();
	} /* while running */
   
	SP_Destroy(hero);
	MP_Destroy(hut);
	SH_Destroy(sprites);
	IF_Destroy();

	return 0;
}
