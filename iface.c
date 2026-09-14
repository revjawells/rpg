#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "config.h"
#include "iface.h"
#include "error.h"

#include "sprite.h"

SDL_Window *win;
SDL_Renderer *ren;

void IF_Create(void)
{
	/* initialize SDL and its components */
   VTRY(SDL_Init(SDL_INIT_EVERYTHING), 0);
   VTRY((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG), IMG_INIT_PNG);

	/* create a window and renderer */
   SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &ren);
	SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

/* remove these as we don't need fullscreen?
   SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
   SDL_RenderSetLogicalSize(ren, WIDTH, HEIGHT);
*/
}

void IF_Destroy(void)
{
   SDL_DestroyRenderer(ren);
   SDL_DestroyWindow(win);

	IMG_Quit();
   SDL_Quit();
}

SDL_Texture *IF_Load(const char *file)
{
   SDL_Texture *t;
   
   t = IMG_LoadTexture(ren, file);
	if (t == NULL) {
		error(IMG_GetError());
	}

   return t;
}

/*
void IF_Scale(SDL_Texture *t, SDL_Renderer *r, int x, int y, int w, int h)
{
   SDL_Rect dest;
   
   dest.x = x;
   dest.y = y;
   dest.h = h;
   dest.w = w;
   
   SDL_RenderCopy(r, t, NULL, &dest);
}
*/

void IF_Render(sprite *s)
{
   SDL_RenderClear(ren);
	SDL_RenderCopy(ren, s->t, NULL, s->pos);

   SDL_RenderPresent(ren);
}
