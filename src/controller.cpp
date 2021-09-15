#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

//****************************************************//
//*****     Controlled Handle Input Method      ******//
//****************************************************//

//void Controller::HandleInput2(bool &running, Grid* grid, Uint32 &target_refresh, bool &go, bool &step) const{   //Take in control references
void Controller::HandleInput2(bool &running, std::shared_ptr <Grid> grid, std::shared_ptr <Grid> next_grid, Uint32 &target_refresh, bool &go, bool &step, bool &skip_update) const{   //Take in control references
  SDL_Event e;
  //Limits of grid update speed
  Uint32 lower_limit = 32;
  Uint32 upper_limit = 4096;

  //Event processing loop
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;                              //If "Quit" have been received, terminate the game
    }else if (e.type == SDL_KEYDOWN) {              //If the event if a key press, decide upon
      switch (e.key.keysym.sym) {
        case SDLK_RETURN:                           // RETURN key control wether the grid is running or not
            if(go==true)
              go=false;
            else
              go=true;
          break;

        //**********************************
        case SDLK_m:                                // m key controls if the grid takes a step forward
            if(step==false)
              step=true;
          break;

        //**********************************
        case SDLK_w:                                                  // w key controls the ZOOM IN for the grid
            if(grid->_cells_displayed_y > grid->_max_zoom_in){        // Only allow a ZOOM IN if the current number of cells displayed in the y axis
                                                                      // is above the limit
              //The first upper left cell displayed is changed
              grid->_first_x++;
              grid->_first_y++;

              //The number of cells displayed in both axis is changed
              grid->_cells_displayed_x=grid->_cells_displayed_x-4;
              grid->_cells_displayed_y=grid->_cells_displayed_y-2;

              //Calculate the offset of the grid based on the new number of cells to be displayed
              // The offset is counted from the upper left corner, and helps maintain grid proportions
              float adjust_x = grid->_width_grid%grid->_cells_displayed_x; 
              float adjust_y = grid->_height_grid%grid->_cells_displayed_y;

                //Update offset
                grid->_offset_x=(int)(adjust_x/2);
                grid->_offset_y=(int)(adjust_y/2);

              //The dimentions of cells, in pixels. Cells are squares so width and height are the same
              Cell::_width = (int) (grid->_width_grid/grid->_cells_displayed_x);
              Cell::_height = Cell::_width;
            }
          break;

        //***************************
        case SDLK_s:                                                  //  s key controls the ZOOM OUT for the grid
            if(grid->_cells_displayed_x < grid->_max_zoom_out){       // Only allow a ZOOM OUT if the current number of cells displayed in the x axis
                                                                      // is bellow the limit

              //Variables that check wether the current cells displayed correspond to one of the special cases
              // these is important to take in consideration because in these cases the zoom of needs to be done
              // differently for the grid proportions to be maintained

              bool top_left = (grid->_first_x==0)&&(grid->_first_y==0); 
              bool bottom_right = (((grid->_first_x + grid->_cells_displayed_x) == grid->_num_cells_x)&&((grid->_first_y + grid->_cells_displayed_y) == grid->_num_cells_y));
              bool bottom_left = ((grid->_first_x==0)&&((grid->_first_y + grid->_cells_displayed_y) == grid->_num_cells_y));
              bool top_right = ((grid->_first_y==0)&&((grid->_first_x + grid->_cells_displayed_x) == grid->_num_cells_x));
              bool top = ((grid->_first_y==0)&&((grid->_first_y + grid->_cells_displayed_y) != grid->_num_cells_y));
              bool right = (((grid->_first_x + grid->_cells_displayed_x) == grid->_num_cells_x)&&(grid->_first_y!=0)&&((grid->_first_y + grid->_cells_displayed_y) != grid->_num_cells_y));
              bool bottom = (((grid->_first_y + grid->_cells_displayed_y) == grid->_num_cells_y)&&(grid->_first_x!=0)&&((grid->_first_x + grid->_cells_displayed_x) != grid->_num_cells_x));
              bool left = ((grid->_first_x==0)&&(grid->_first_y!=0)&&((grid->_first_y + grid->_cells_displayed_y) != grid->_num_cells_y));

              //The first upper left cell displayed is changed
              //Special cases
              if(top_left){}
              else if(top_right){
                grid->_first_x=grid->_first_x-4;

              } else if (bottom_right){
                grid->_first_x=grid->_first_x-4;
                grid->_first_y=grid->_first_y-2;

              } else if(bottom_left){
                grid->_first_y=grid->_first_y-2;

              } else if(top){
                grid->_first_x=grid->_first_x-1;

              } else if(right){
                grid->_first_x=grid->_first_x-4;
                grid->_first_y=grid->_first_y-1;

              } else if(bottom){
                grid->_first_x=grid->_first_x-1;
                grid->_first_y=grid->_first_y-2;

              } else if(left){
                grid->_first_y=grid->_first_y-1;
              }

              else {                          //Grid is not in any special case
                grid->_first_x--;
                grid->_first_y--;
              }

              //The number of cells displayed in both axis is changed
              grid->_cells_displayed_x=grid->_cells_displayed_x+4;
              grid->_cells_displayed_y=grid->_cells_displayed_y+2;

              //Calculate the offset of the grid based on the new number of cells to be displayed
              // The offset is counted from the upper left corner, and helps maintain grid proportions
              float adjust_x = grid->_width_grid%grid->_cells_displayed_x; 
              float adjust_y = grid->_height_grid%grid->_cells_displayed_y;

                //Update offset
                grid->_offset_x=(int)(adjust_x/2);
                grid->_offset_y=(int)(adjust_y/2);

              //The dimentions of cells, in pixels. Cells are squares so width and height are the same
              Cell::_width = (int) (grid->_width_grid/grid->_cells_displayed_x);
              Cell::_height = Cell::_width;  
            }
          break;

          //***************************
          case SDLK_c:  
            if(go == false){
              next_grid->Fill_Grid(0);
              step = true;
              skip_update = true;
            }
          break;

          case SDLK_1: 
            if(go == false){ 
              std::cout<<"Number 1 pressed"<<std::endl;
              step = true;
              skip_update = true;
              next_grid->Reset_Grid_Scope();
              next_grid->Fill_Grid(1);
            }
          break;

          case SDLK_RIGHT:                                                              //  right arrow key pans the grid to the right
            if(  (grid->_first_x + grid->_cells_displayed_x ) <  grid->_num_cells_x){   // Check if we are not already in the right limit of the grid
              grid->_first_x++;
            }
          break;

          case SDLK_LEFT:                                                              //  Left arrow key pans the grid to the left
            if(grid->_first_x>0){                                                      // Check if we are not already in the left limit of the grid
              grid->_first_x--;
            }
          break;

          case SDLK_UP:                                                                //  Up arrow key pans up the grid
            if(grid->_first_y>0){                                                      // Check if we are not already in the upper limit of the grid
              grid->_first_y--;
           }
          break;

          case SDLK_DOWN:                                                              //  Down arrow key pans up the grid
            if((grid->_first_y + grid->_cells_displayed_y ) < grid->_num_cells_y){     // Check if we are not already in the lower limit of the grid
              grid->_first_y++;
           }
          break;

          case SDLK_j:                                                                 //  j key speeds up the grid updating cycle
            if(target_refresh > lower_limit)                                           // if we are still above the speed limit
              target_refresh = target_refresh/2;
          break;

          case SDLK_k:                                                                 //  k key slows down the grid updating cycle
            if(target_refresh < upper_limit)
              target_refresh = target_refresh*2;
          break;
      }
    }

      if( e.type == SDL_MOUSEBUTTONDOWN ){                                                                 //  check if the mouse button has been clicked
          for (auto i : grid->_the_grid){                                                                  //  traverse trrough the grid array
            if((i->_pos.x>=grid->_first_x)&&(i->_pos.x<(grid->_first_x+grid->_cells_displayed_x)))
              if((i->_pos.y>=grid->_first_y)&&(i->_pos.y<(grid->_first_y+grid->_cells_displayed_y)))
                i->handleEvent(grid->_first_x, grid->_first_y, grid->_offset_x, grid->_offset_y);      //  if the cell is being displayed, proceed to check if it was clicked
          }

      }
  }
}
