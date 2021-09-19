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

    void Handle_Input(bool &running, std::shared_ptr <Grid> act_grid, std::shared_ptr <Grid> next_grid, 
                            Uint32 &target_refresh, bool &go, bool &step, bool &skip_update)const;          //  Method that handles the user input and updates
                                                                                                            //  all the corresponding variables that
                                                                                                            //  are passed by reference to it 

    void Read_Or_Write(int file_number, std::shared_ptr <Grid> act_grid, std::shared_ptr <Grid> next_grid, 
                    bool &step, bool &skip_update) const;                                                   //  Method that decides if we are reading or writing
                                                                                                            //  To a Figure slot, and calls the correct method
                                                                                                            //  acoordingly

};

#endif