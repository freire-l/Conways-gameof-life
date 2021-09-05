#ifndef GAME_H
#define GAME_H

#include <random>
#include <thread>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "cell.h"

class Game {
 public:
  /*
    Constructor for Game Class, takes the sizes of both axis of the screen to be created
    Initializes both Grids to be used in the game, the actual grid, and the one used to compute
    the nest state of the game
  */
  Game (int width_grid, int height_grid);

  /*
    Method that controls the game main loop, takes a reference to the controller and renderer object
    Handles the input
    Updates the grid
    Renders the grid
  */
  void Run(Controller const &controller, Renderer &renderer);
  void Update_next_grid();

  static void Update_cells_wrapper(Game *game,Cell *i);
  void Update_cells(Cell *i);

 private:
  Grid* _actual_grid;     //Pointer to the grid object that would be feeding the screen render                    
  Grid* _next_grid;       //Pointer to the grid object that will hold the ccalculations for the next render
  bool go = false;        //Variable that controls wether the game is alowed to continue or not
  bool step = false;      //Variable that controls if the game takes a single step forward
  int _width_grid;
  int _height_grid;

};


#endif