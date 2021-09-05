#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "cell.h"
#include "grid.h"

class Renderer{
 public:
  /*
    Constructor for Renderer Class, takes the sizes of both axis of the screen to be created
    Initializes SDL, creates the window and then a new Renderer object
  */
  Renderer(const std::size_t screen_width, const std::size_t screen_height);

  ~Renderer();                                                                  //Destructor

  void Render2(Grid* grid);
  void DrawCell (Cell *i, Grid *grid);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;     //Pointer to the sdl window to be created
  SDL_Renderer *sdl_renderer; //Pointer to be renderer to be created
  //SDL_Surface *sdl_surface;

  const std::size_t screen_width;      //width of the screen in pixels
  const std::size_t screen_height;     //height of the screen in pixels

};

#endif