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
	sprite *sp;
	sprite *hero;
   
	IF_Create();
	atexit(IF_Destroy);

	sprites = SH_Create("assets/tiles.png", TILESIZE, TILESIZE);

	sp = SP_Create(sprites, 0, 0, 0);
	hero = SP_Create(sprites, 25, 3, 3);

	while (!quit) {
		/* get user input */
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = TRUE;
			}

/* TEMP - disable key movement 
				switch (e.key.keysym.sym) {
else if (e.type == SDL_KEYDOWN) {
						case DO_UP:
							SP_Update(s, 0, -1);
							break;

						case DO_DOWN:
							SP_Update(s, 0, +1);
							break;

						case DO_LEFT:
							SP_Update(s, -1, 0);
							break;

						case DO_RIGHT:
							SP_Update(s, +1, 0);
							break;

						case DO_START:
							SP_Move(s, WIDTH / 2, HEIGHT / 2);
							break;

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

		for (int row = 0; row < MAPSIZE; row++) {
			sp->x = row;

			for (int col = 0; col < MAPSIZE; col++) {
				sp->tile = map[col][row];		
				sp->y = col;
				SP_Draw(sp);
			}
		}

		SP_Draw(hero);

		/* render the scene */
		IF_Render();
	} /* while running */
   
	SP_Destroy(hero);
	SP_Destroy(sp);
	SH_Destroy(sprites);

	return 0;
}
