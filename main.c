#include "config.h"

#include "iface.h"
#include "boolean.h"
#include "sprite.h"

int main(int argc, char **argv)
{
   SDL_Event e;
   
   boolean quit = FALSE;
	sprite *s;
   
   IF_Create();
	atexit(IF_Destroy);
	s = SP_Create("assets/hero.png", WIDTH / 2, HEIGHT / 2);

   while (!quit) 
     {
	/* get user input */
	while (SDL_PollEvent(&e))
	  {
		if (e.type == SDL_QUIT) {
			quit = TRUE;
		} else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
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
	  }
	
	/* render the scene */
	IF_Render(s);
     }
   
   return 0;
}
