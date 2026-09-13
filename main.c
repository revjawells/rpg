#include "error.h"
#include "iface.h"
#include "boolean.h"

int main(int argc, char **argv)
{
   SDL_Event e;
   
   boolean quit = FALSE;
   
   IF_Create();

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
	IF_Render(img, ren, 0, 0);
     }
   
   IF_Destroy();
   return 0;
}
