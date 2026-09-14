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
		switch (e.type) {
			case SDL_QUIT:
			case SDL_KEYDOWN:
			case SDL_MOUSEBUTTONDOWN:
				quit = TRUE;
				break;

			default: break;
		}
	  }
	
	/* render the scene */
	IF_Render(s);
     }
   
   return 0;
}
