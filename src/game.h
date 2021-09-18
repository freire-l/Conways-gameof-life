#ifndef GAME_H
#define GAME_H

#include <random>
#include <thread>
#include <memory>
#include <mutex>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "cell.h"

class Game {
 public:

  Game (int width_grid, int height_grid);                             //  Constructor for Game Class, takes the sizes of both axis of the screen to be created
                                                                      //  Initializes both Grids to be used in the game, the actual grid, and the one used to compute
                                                                      //  the next state of the game

  void Run(Controller const &controller, Renderer &renderer);         //  Method that controls the game main loop, takes a reference to the controller and renderer object
                                                                      //  Handles the input
                                                                      //  Updates the grid
                                                                      //  Renders the grid   

  void Update_next_grid();                                            //  Method that handles next grid computation based on current grid values
                                                                      //  This is the method that controls concurrent execution

  void Update_cell(Cell *i);                                          //  Method that counts the number of alive neighbors in a current cell and decides
                                                                      //  wether that cell should be alive or not in the next cycle 

  void Update_several_cells(int start, int end);                      //  Method that takes a range of cells and call the method Update_cell on
                                                                      //  each of them

  static void Update_several_wrapper(Game* game, int start, int end); //  Wrapper for concurrent excecution, wraps the Update_several_cells method

 private:
  std::shared_ptr<Grid> _actual_grid;                                 //  Pointer to the grid object that would be feeding the screen render 
  std::shared_ptr<Grid> _next_grid;                                   //  Pointer to the grid object that will hold the calculations for the next render
  bool go = false;                                                    //  Variable that controls wether the game is alowed to continue or not
  bool step = false;                                                  //  Variable that controls if the game takes a single step forward
  bool skip_update = false;                                           //  Variable that controls if the are skiping th normal update method after a file read
  int _width_grid;                                                                                        
  int _height_grid;

  std::mutex _mutex;                                                  //  Mutex for protecting the Grid array during concurrent execution

};


#endif