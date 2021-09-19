#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "cell.h"
#include "grid.h"

class Renderer{
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);    //  Constructor for Renderer Class, takes the sizes of both axis of
                                                                                //  the screen to be created
                                                                                //  Initializes SDL, creates the window and then a new Renderer object

  ~Renderer();                                                                  //  Destructor

  void Render(std::shared_ptr <Grid> grid);                                    //  Method that renders a grid

  void Draw_Cell (Cell *i, std::shared_ptr <Grid> grid);                         //  Method that renders a specific Cell

 private:
  SDL_Window *sdl_window;                                                       //  Pointer to the sdl window to be created
  SDL_Renderer *sdl_renderer;                                                   //  Pointer to be renderer to be created

  const std::size_t screen_width;                                               //  width of the screen in pixels
  const std::size_t screen_height;                                              //  height of the screen in pixels

};

#endif