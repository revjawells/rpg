#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "iface.h"
#include "error.h"

static const int WIDTH = 320;
static const int HEIGHT = 200;

static SDL_Window *win;

SDL_Renderer *ren;
SDL_Texture *img;

SDL_Texture *IF_Load(const char *file, SDL_Renderer *r)
{
   SDL_Texture *t;
   
   t = IMG_LoadTexture(r, file);

   return t;
}

void IF_Create(void)
{
   VTRY(SDL_Init(SDL_INIT_EVERYTHING), 0);

   SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &win, &ren);
   SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
   SDL_RenderSetLogicalSize(ren, WIDTH, HEIGHT);
   
   VTRY((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG), IMG_INIT_PNG);
   
   img = IF_Load("image.png", ren);
}

void IF_Destroy(void)
{
   SDL_DestroyTexture(img);
   
   SDL_DestroyRenderer(ren);
   SDL_DestroyWindow(win);

   SDL_Quit();
}

void IF_Scale(SDL_Texture *t, SDL_Renderer *r, int x, int y, int w, int h)
{
   SDL_Rect dest;
   
   dest.x = x;
   dest.y = y;
   dest.h = h;
   dest.w = w;
   
   SDL_RenderCopy(r, t, NULL, &dest);
}

void IF_Render(SDL_Texture *t, SDL_Renderer *r, int x, int y)
{
   int w, h;

   SDL_RenderClear(ren);

   SDL_QueryTexture(t, NULL, NULL, &w, &h);
   IF_Scale(t, r, x, y, w, h);

   SDL_RenderPresent(ren);
}
