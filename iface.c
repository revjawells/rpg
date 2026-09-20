#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "config.h"
#include "iface.h"
#include "error.h"

#include "sprite.h"
#include "player.h"

SDL_Window *win;
SDL_Renderer *ren;

TTF_Font *font;
SDL_Color fgcolor = {0xFF, 0xFF, 0xFF};
SDL_Color bgcolor = {0x00, 0x00, 0x00};

void IF_Create(void)
{
	/* initialize SDL and its components */
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		eprintf(SDL_GetError());

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
		eprintf(IMG_GetError());

	if (TTF_Init() != 0)
		eprintf(TTF_GetError());

	font = TTF_OpenFont("assets/PressStart2P-vaV7.ttf", FONTSIZE);
	if (font == NULL)
		eprintf("failed to load font: ", TTF_GetError());

	/* create a window and renderer */
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &ren);
	SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
}

void IF_Destroy(void)
{
	TTF_CloseFont(font);

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture *IF_Load(const char *file)
{
   SDL_Texture *t;
   
   t = IMG_LoadTexture(ren, file);
	if (t == NULL) {
		eprintf(IMG_GetError());
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

	if (s != NULL && s->tile >= 0) {
		shrow = s->tile / SHEETSIZE;
		shcol = s->tile % SHEETSIZE;

		src.w = src.h = TILESIZE; 
		src.x = shcol * (TILESIZE + 2); // was TILESIZE + 1
		src.y = shrow * (TILESIZE + 2);

		dest.w = dest.h = TILESIZE * SCALE; 
		dest.x = x * TILESIZE * SCALE;
		dest.y = y * TILESIZE * SCALE;

		SDL_RenderCopy(ren, s->sheet->t, &src, &dest);
	}
}

void IF_DrawStatus(player_t *p)
{
	SDL_Surface *surf;
	SDL_Texture *status;
	
	SDL_Rect dest;
	int w, h;

	char buffer[BUFSIZE];

	/* render data */
	snprintf(buffer, BUFSIZE,
		"-%.4s-\nLV%4d\nHP%4d\nMP%4d\nG%5d\nE%5d", p->name, p->level, p->hp, p->mp, p->gold, p->xp);

	/* render surface */
	surf = TTF_RenderUTF8_Shaded_Wrapped(font, buffer, fgcolor, bgcolor, 0);
	status = SDL_CreateTextureFromSurface(ren, surf);

	SDL_QueryTexture(status, NULL, NULL, &w, &h);
	dest.x = 32;
	dest.y = 32;
	dest.w = w;
	dest.h = h;

	SDL_RenderCopy(ren, status, NULL, &dest);

	SDL_FreeSurface(surf);
	SDL_DestroyTexture(status);
}
