#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "cell.h"
#include "grid.h"

class Renderer{
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);

  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);
  void Render2(Grid* grid);
  void DrawCell (Cell *i, Grid *grid);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Surface *sdl_surface;

  const std::size_t screen_width;
  const std::size_t screen_height;

};

#endif