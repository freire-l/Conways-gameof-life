#include "renderer.h"
#include <iostream>
#include <string>

//****************************************************//
//*****       Renderer Class Constructor        ******//
//****************************************************//

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Conways Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

}

//****************************************************//
//*****        Renderer Class Destructor        ******//
//****************************************************//
Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  sdl_window = NULL;
  SDL_DestroyRenderer(sdl_renderer);
  sdl_window = NULL;
  SDL_Quit();
}

//****************************************************//
//*****            Draw Cell Method             ******//
//****************************************************//
void Renderer::DrawCell (Cell *cell, std::shared_ptr <Grid> grid){

    int first_x = grid ->_first_x;
    int first_y = grid ->_first_y;
    int offset_x = grid ->_offset_x;
    int offset_y = grid ->_offset_y;

    //Obtain x and y coordinates of the cell, in pixels
    int x = (((cell->_pos.x)-first_x)*(cell->_width)) + offset_x;
    int y = (((cell->_pos.y)-first_y)*(cell->_height))+ offset_y;

    //  Set dimentions for the square
    SDL_Rect draw_dims = { x+1, y+1, cell->_height-2,  cell->_width-2 };

    // If the cell is alive, fill it yellow
    if(cell->_is_alive == true)
    {
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0FF, 0x00, 0xFF); //YELLOW
      SDL_RenderFillRect(sdl_renderer, &draw_dims);
    }

    //  If the cell is dead, fill it grey
    else
    {
      SDL_SetRenderDrawColor(sdl_renderer, 0x99, 0x0A3, 0xA4, 0xFF); //GREY
      SDL_RenderFillRect(sdl_renderer, &draw_dims);
    }

}

//****************************************************//
//*****               Render Method             ******//
//****************************************************//
void Renderer::Render2(std::shared_ptr <Grid> grid){

          //SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF); //BLACK
          //SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0FF, 0x00, 0xFF); //YELLOW
          //SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0FF, 0xFF, 0xFF); //WHITE

  //  Set draw color
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0FF, 0xFF, 0xFF); //WHITE

  //  Clear Screen
  SDL_RenderClear(sdl_renderer);

  //Traverse the grid array, only display cells that are inside the corrently zoomed area    
  for (auto i : grid->_the_grid){
    if(((i->_pos.x>=grid->_first_x)&&(i->_pos.x<(grid->_first_x+grid->_cells_displayed_x)))&&((i->_pos.y>=grid->_first_y)&&(i->_pos.y<(grid->_first_y+grid->_cells_displayed_y)))){
      DrawCell( i, grid);         //Render a Cell
    }
  }
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
