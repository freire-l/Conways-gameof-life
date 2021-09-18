#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include "snake.h"
#include "cell.h"
#include "grid.h"

//Forward declaration
class Grid; 

class Controller {
 public:

  //void HandleInput2(bool &running, Grid* grid, Uint32 &target_refresh, bool &go, bool &step) const;       //  Method that handles the user input and updates
                                                                                                          //  all the corresponding variables that
                                                                                                          //  are passed by reference to it 

    void HandleInput2(bool &running, std::shared_ptr <Grid> act_grid, std::shared_ptr <Grid> next_grid, Uint32 &target_refresh, bool &go, bool &step, bool &skip_update)const;  //  Method that handles the user input and updates

    void ReadOrWrite(int file_number, std::shared_ptr <Grid> act_grid, std::shared_ptr <Grid> next_grid, bool &step, bool &skip_update) const;

};

#endif