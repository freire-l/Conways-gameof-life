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

  Game (int width_grid, int height_grid);                     //  Constructor for Game Class, takes the sizes of both axis of the screen to be created
                                                              //  Initializes both Grids to be used in the game, the actual grid, and the one used to compute
                                                              //  the nest state of the game

  void Run(Controller const &controller, Renderer &renderer); //  Method that controls the game main loop, takes a reference to the controller and renderer object
                                                              //  Handles the input
                                                              //  Handles the input
                                                              //  Renders the grid   

  void Update_next_grid();                                    //  Method that handles next grid computation based on current grid values

  void Update_cells(Cell *i);                                 //  Method that counts the number of alive neighbors in a current cell and decides
  //void Update_cells(std::shared_ptr<Cell> i);                                 //  Method that counts the number of alive neighbors in a current cell and decides
                                                              //  wether that cell should be alive or not in the next cycle 

  void Update_cells2(int start, int end);
  static void Update_cells_wrapper(Game *game,Cell *i);       //  Wrapper for concurrent excecution
  //static void Update_cells_wrapper(Game* game, std::shared_ptr<Cell> i); //  Wrapper for concurrent excecution
static void Update_bunch_wrapper(Game* game, int start, int end);

 private:
  //Grid* _actual_grid;     //Pointer to the grid object that would be feeding the screen render                    
  //Grid* _next_grid;       //Pointer to the grid object that will hold the calculations for the next render
  std::shared_ptr<Grid> _actual_grid;     //Pointer to the grid object that would be feeding the screen render 
  std::shared_ptr<Grid> _next_grid;       //Pointer to the grid object that will hold the calculations for the next render
  bool go = false;        //Variable that controls wether the game is alowed to continue or not
  bool step = false;      //Variable that controls if the game takes a single step forward
  bool skip_update = false;
  int _width_grid;
  int _height_grid;

  std::mutex _mutex;

};


#endif