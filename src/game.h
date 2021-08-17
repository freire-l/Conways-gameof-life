#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "cell.h"
//#include "snake.h"

class Game {
 public:
 ///
  //Agosto 3
  //Game(int size_grid);
  Game (int width_grid, int height_grid);
///
  void Run(Controller const &controller, Renderer &renderer);
  void Update_next_grid();

 private:
  //std::vector<Cell*>* _actual_grid;
  //std::vector<Cell*>* _next_grid;
  Grid* _actual_grid;
  Grid* _next_grid;

  //******* Grid drivers ********

  ///
    //Agosto 3
    /*
  const int _num_cells = 40;
  int _first_cell = 0;
  */

  
  //const int _num_cells_x = 80;
  //const int _num_cells_y = 40;

  //const int _num_cells_x = 240;
  //const int _num_cells_y = 120;

  const int _num_cells_x = 720;
  const int _num_cells_y = 360;

  //const int _num_cells_x = 2160;
  //const int _num_cells_y = 1080;

  //le sumas el doble, y de ahi puedes poner las nuevas celdas como celdas de inicio
  /*
  int _first_cell_x = 80-1;
  int _first_cell_y = 40-1;
  */
  
  ///
  //******* Grid drivers ********  


  bool go = false;

  bool step = false;

///
  //Agosto 3
  //int _size_grid;

  int _width_grid;
  int _height_grid;

///


  //const int _size_grid = 640;
};

/*

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};
*/

#endif