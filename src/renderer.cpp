#include "renderer.h"
#include <iostream>
#include <string>
#include <thread>

/*Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {*/

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height
                   )
    : screen_width(screen_width),
      screen_height(screen_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Conways Game of Life", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

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

  //surface
  /*
            //Get window surface
            sdl_surface = SDL_GetWindowSurface( sdl_window );

            //Fill the surface white
            SDL_FillRect( sdl_surface, NULL, SDL_MapRGB( sdl_surface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( sdl_window );
  */

  //wait two seconds
  //SDL_Delay( 1000 );
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  sdl_window = NULL;
  SDL_Quit();
}
//void Renderer::DrawCell(Cell* cell, int &first_x, int &first_y, int offset_x, int offset_y){
void Renderer::DrawCell (Cell *cell, Grid *grid){
  if(((cell->_pos.x>=grid->_first_x)&&(cell->_pos.x<(grid->_first_x+grid->_cells_displayed_x)))&&((cell->_pos.y>=grid->_first_y)&&(cell->_pos.y<(grid->_first_y+grid->_cells_displayed_y))))
  {
    int first_x = grid ->_first_x;
    int first_y = grid ->_first_y;
    int offset_x = grid ->_offset_x;
    int offset_y = grid ->_offset_y;

      //SDL_Texture* mTexture = NULL;

      //SDL_Rect draw_dims = { cell->_pos.x, cell->_pos.y, cell->_height,  cell->_width };
      int x = (((cell->_pos.x)-first_x)*(cell->_width)) + offset_x;
      int y = (((cell->_pos.y)-first_y)*(cell->_height))+ offset_y;

      //SDL_Rect draw_dims = { x, y, cell->_height,  cell->_width };
      SDL_Rect draw_dims = { x+1, y+1, cell->_height-2,  cell->_width-2 };


      if(cell->_is_alive == true)
      {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0FF, 0x00, 0xFF); //YELLOW
        SDL_RenderFillRect(sdl_renderer, &draw_dims);
        //std::cout<<"sup"<<std::endl;
      }

      else
      {
        SDL_SetRenderDrawColor(sdl_renderer, 0x99, 0x0A3, 0xA4, 0xFF); //GREY
        SDL_RenderFillRect(sdl_renderer, &draw_dims);
        //SDL_RenderDrawRect(sdl_renderer, &draw_dims);
        //std::cout<<"no"<<std::endl;
      }

  }

  //SDL_DestroyTexture( mTexture );
}
/*
void Renderer::DrawGrid (Cell *i, Grid *grid)
{
  if(((i->_pos.x>=grid->_first_x)&&(i->_pos.x<(grid->_first_x+grid->_cells_displayed_x)))&&((i->_pos.y>=grid->_first_y)&&(i->_pos.y<(grid->_first_y+grid->_cells_displayed_y))))
    DrawCell(i,grid->_first_x, grid->_first_y, grid->_offset_x, grid->_offset_y);
}
*/
//void Renderer::Render2(Cell* cell){
//void Renderer::Render2(std::vector<Cell*> grid, int &first_x, int &first_y, int &cells_displayed){
void Renderer::Render2(Grid* grid){
  // Clear screen
  //SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF); //BLACK
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0FF, 0xFF, 0xFF); //WHITE
  SDL_RenderClear(sdl_renderer);

  //SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0FF, 0x00, 0xFF); //YELLOW

  //SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x0FF, 0xFF, 0xFF); //WHITE

  //una variable que te diga cuales se van a desplegar de todas las que hay

///
  //Agosto 3
      /*
      for (auto i : grid->_the_grid){
        if((i->_pos.x>=grid->_first_x)&&(i->_pos.x<(grid->_first_x+grid->_cells_displayed)))
          if((i->_pos.y>=grid->_first_y)&&(i->_pos.y<(grid->_first_y+grid->_cells_displayed)))
            DrawCell(i,grid->_first_x, grid->_first_y);
      }
      */

      /*
      for (auto i : grid->_the_grid){
        if((i->_pos.x>=grid->_first_x)&&(i->_pos.x<(grid->_first_x+grid->_cells_displayed_x)))
          if((i->_pos.y>=grid->_first_y)&&(i->_pos.y<(grid->_first_y+grid->_cells_displayed_y)))
          {}
            //DrawCell(i,grid->_first_x, grid->_first_y, grid->_offset_x, grid->_offset_y);
      }
      */
    /*
     std::vector <std::thread> threads;
      for (auto i : grid->_the_grid){
        threads.push_back(std::thread(DrawCell, i, grid));
      }

      for (auto &t : threads){
        t.join();
      }
      */

      
      for (auto i : grid->_the_grid){
        DrawCell( i, grid);
      }

      

///
    // Update Screen
  SDL_RenderPresent(sdl_renderer);


}
/*
void Renderer::Render(Snake const snake, SDL_Point const &food) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}
*/
void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
