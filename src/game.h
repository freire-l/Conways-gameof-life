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
  Game(int size_grid);
  void Run(Controller const &controller, Renderer &renderer);
  void Update_next_grid();

 private:
  //std::vector<Cell*>* _actual_grid;
  //std::vector<Cell*>* _next_grid;
  Grid* _actual_grid;
  Grid* _next_grid;

  //******* Grid drivers ********
  const int _num_cells = 16;
  int _first_cell = 0;
  //******* Grid drivers ********  


  bool go = false;

  bool step = false;

  int _size_grid;
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