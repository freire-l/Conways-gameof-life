#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "cell.h"
#include "grid.h"

//Forward declaration
class Grid; 

class Controller {
 public:

  void HandleInput2(bool &running, Grid* grid, Uint32 &target_refresh, bool &go, bool &step) const;       //  Method that handles the user input and updates
                                                                                                          //  all the corresponding variables that
                                                                                                          //  are passed by reference to it 

};

#endif