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

void IF_Clear(void)
{
	SDL_RenderClear(ren);
}

void IF_Render(void)
{
	SDL_RenderPresent(ren);
}

void IF_Draw(sprite_t *s, int x, int y)
{
	static SDL_Rect src, dest;
	int shrow, shcol;

	shrow = s->tile / SHEETSIZE;
	shcol = s->tile % SHEETSIZE;

	src.w = src.h = TILESIZE; 
	src.x = shcol * (TILESIZE + 2); // was TILESIZE + 1
	src.y = shrow * (TILESIZE + 2);

	dest.w = dest.h = TILESIZE; 
	dest.x = x * TILESIZE;
	dest.y = y * TILESIZE;

	SDL_RenderCopy(ren, s->sheet->t, &src, &dest);
}
