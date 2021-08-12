#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}
/*
bool Controller::handleEventCoordinate(int x_cell, int y_cell, SDL_Event* e){
    //If mouse event happened
    bool to_return = false;
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );

        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < _pos.x )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > _pos.x + _width)
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < _pos.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > _pos.y + _height)
        {
            inside = false;
        }

        //Mouse is outside button
        if( !inside )
        {
            //std::cout<<"afuera"<<std::endl;
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
                //mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;
            
                case SDL_MOUSEBUTTONDOWN:
                //mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                std::cout<<"centro click"<<std::endl;
                //toggle_life();
                to_return = true;
                break;
                
                case SDL_MOUSEBUTTONUP:
                //mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                break;
            }
        }
    }
    return to_return;
}
*/
//void Controller::HandleInput2(bool &running, std::vector<std::vector<Cell*>> grid, Cell* cell) const {
//void Controller::HandleInput2(bool &running, std::vector<std::vector<int>> grid, int num_cells, int size_grid, Cell* cell) const {
//void Controller::HandleInput2(bool &running, Grid* grid, int &first_x, int &first_y, int &cells_displayed, Uint32 &target_refresh) const{
void Controller::HandleInput2(bool &running, Grid* grid, Uint32 &target_refresh, bool &go, bool &step) const{
  SDL_Event e;
  //limits of speed
  Uint32 lower_limit = 32;
  Uint32 upper_limit = 4096;

  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    }else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_RETURN:
            if(go==true)
              go=false;
            else
              go=true;
          break;

        case SDLK_m:
            if(step==false)
              step=true;

          break;
        case SDLK_w:
            //if(cells_displayed > 4)           
            //if(grid->_cells_displayed > 4) //
            if(grid->_cells_displayed_y > 8) //Agosto 3
            {
              grid->_first_x++;
              grid->_first_y++;
              //
              /*
              grid->_cells_displayed=grid->_cells_displayed-2;
              Cell::_height = grid->_size_grid/grid->_cells_displayed;
              Cell::_width = Cell::_height;

              std::cout<<"ZOOM IN***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed: " << grid->_cells_displayed<< "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
              */

              grid->_cells_displayed_x=grid->_cells_displayed_x-4; //Agosto 3
              grid->_cells_displayed_y=grid->_cells_displayed_y-2; //Agosto 3
              //Cell::_height = grid->_height_grid/grid->_cells_displayed_y;  //Agosto 3
              Cell::_width = grid->_width_grid/grid->_cells_displayed_x;    //Agosto 3
              Cell::_height = Cell::_width;

              std::cout<<"ZOOM IN***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed X: " << grid->_cells_displayed_x << " num_cells_displayed Y: " << grid->_cells_displayed_y << "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;

              //

              
            }
          break;

        case SDLK_s:
            //if(grid->_cells_displayed < grid->_max_zoom_out)
            if(grid->_cells_displayed_x < grid->_max_zoom_out) //Agosto 3
            {
              /*
              bool top_left = (grid->_first_x==0)&&(grid->_first_y==0);   //top left corner
              bool bottom_right = (((grid->_first_x + grid->_cells_displayed) == grid->_num_cells)&&((grid->_first_y + grid->_cells_displayed) == grid->_num_cells)); //bottom right coner
              bool bottom_left = ((grid->_first_x==0)&&((grid->_first_y + grid->_cells_displayed) == grid->_num_cells));   //bottom left corner
              bool top_right = ((grid->_first_y==0)&&((grid->_first_x + grid->_cells_displayed) == grid->_num_cells));      //top right corner
              bool top = ((grid->_first_y==0)&&((grid->_first_y + grid->_cells_displayed) != grid->_num_cells));
              bool right = (((grid->_first_x + grid->_cells_displayed) == grid->_num_cells)&&(grid->_first_y!=0)&&((grid->_first_y + grid->_cells_displayed) != grid->_num_cells));
              bool bottom = (((grid->_first_y + grid->_cells_displayed) == grid->_num_cells)&&(grid->_first_x!=0)&&((grid->_first_x + grid->_cells_displayed) != grid->_num_cells));
              bool left = ((grid->_first_x==0)&&(grid->_first_y!=0)&&((grid->_first_y + grid->_cells_displayed) != grid->_num_cells));
             */
              /// Agosto 3
              
              bool top_left = (grid->_first_x==0)&&(grid->_first_y==0);   //top left corner
              bool bottom_right = (((grid->_first_x + grid->_cells_displayed_x) == grid->_num_cells_x)&&((grid->_first_y + grid->_cells_displayed_y) == grid->_num_cells_y)); //bottom right coner
              bool bottom_left = ((grid->_first_x==0)&&((grid->_first_y + grid->_cells_displayed_y) == grid->_num_cells_y));   //bottom left corner
              bool top_right = ((grid->_first_y==0)&&((grid->_first_x + grid->_cells_displayed_x) == grid->_num_cells_x));      //top right corner
              bool top = ((grid->_first_y==0)&&((grid->_first_y + grid->_cells_displayed_y) != grid->_num_cells_y));
              bool right = (((grid->_first_x + grid->_cells_displayed_x) == grid->_num_cells_x)&&(grid->_first_y!=0)&&((grid->_first_y + grid->_cells_displayed_y) != grid->_num_cells_y));
              bool bottom = (((grid->_first_y + grid->_cells_displayed_y) == grid->_num_cells_y)&&(grid->_first_x!=0)&&((grid->_first_x + grid->_cells_displayed_x) != grid->_num_cells_x));
              bool left = ((grid->_first_x==0)&&(grid->_first_y!=0)&&((grid->_first_y + grid->_cells_displayed_y) != grid->_num_cells_y));
              
              ///
              //if(top_left){break;} //agosto 3
              if(top_left){}
              else if(top_right){
                std::cout<<"three 3*** "<<std::endl;
                grid->_first_x=grid->_first_x-4; //agosto 3
              } else if (bottom_right){
                std::cout<<"four 4*** "<<std::endl;
                grid->_first_x=grid->_first_x-4; //agosto 3
                grid->_first_y=grid->_first_y-2;
              } else if(bottom_left){
                std::cout<<"five 5*** "<<std::endl;
                grid->_first_y=grid->_first_y-2;
              } else if(top){
                std::cout<<"five 6*** "<<std::endl;
                grid->_first_x=grid->_first_x-1;
              } else if(right){
                std::cout<<"five 7*** "<<std::endl;
                //grid->_first_x=grid->_first_x-2;  //agosto 3
                //grid->_first_y=grid->_first_y-1;  //agosto 3
                grid->_first_x=grid->_first_x-4;  //agosto 3
                grid->_first_y=grid->_first_y-1;  //agosto 3
              } else if(bottom){
                std::cout<<"five 8*** "<<std::endl;
                grid->_first_x=grid->_first_x-1;
                grid->_first_y=grid->_first_y-2;

              } else if(left){
                std::cout<<"five 9*** "<<std::endl;
                grid->_first_y=grid->_first_y-1;

              }

              else {
                grid->_first_x--;
                grid->_first_y--;
              }

              //
              /*
              grid->_cells_displayed=grid->_cells_displayed+2;
              Cell::_height = grid->_size_grid/grid->_cells_displayed;
              Cell::_width = Cell::_height;

              std::cout<<"ZOOM OUT***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed: " << grid->_cells_displayed<< "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
              */

              grid->_cells_displayed_x=grid->_cells_displayed_x+4; //Agosto 3
              grid->_cells_displayed_y=grid->_cells_displayed_y+2; //Agosto 3
              //Cell::_height = grid->_height_grid/grid->_cells_displayed_y;  //Agosto 3
              Cell::_width = grid->_width_grid/grid->_cells_displayed_x;    //Agosto 3
              Cell::_height = Cell::_width;

              std::cout<<"ZOOM OUT***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed X: " << grid->_cells_displayed_x << " num_cells_displayed Y: " << grid->_cells_displayed_y << "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
              //
              
                
            }
          break;

          case SDLK_RIGHT:
            //std::cout<<"first: " << first_x << "  num_cells_displayed: " << (16-(first_x*2)) << "  result of formula: " << (first_x   + (16-(first_x*2))        ) << std::endl;
            //if(first_x+(16-(first_x*2))<16){
            //if(  (first_x   + (16-(first_x*2))        )   <     16){
            //if(  (grid->_first_x   + grid->_cells_displayed       )   <     grid->_num_cells){
            if(  (grid->_first_x   + grid->_cells_displayed_x       )   <     grid->_num_cells_x){    //Agosto 3
              grid->_first_x++;
              std::cout<<"RIGHT***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed X: " << grid->_cells_displayed_x << " num_cells_displayed Y: " << grid->_cells_displayed_y << "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
              //std::cout<<"RIGHT***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed: " << grid->_cells_displayed<< "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
            }

          break;

          case SDLK_LEFT:
            if(grid->_first_x>0){
              grid->_first_x--;
              //std::cout<<"LEFT***   First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed: " << grid->_cells_displayed<< "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
              std::cout<<"LEFT**  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed X: " << grid->_cells_displayed_x << " num_cells_displayed Y: " << grid->_cells_displayed_y << "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
            }

          break;

          case SDLK_UP:
            if(grid->_first_y>0){
              grid->_first_y--;
              //std::cout<<"UP***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y<<" num_cells_displayed: " << grid->_cells_displayed << "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
              std::cout<<"UP***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed X: " << grid->_cells_displayed_x << " num_cells_displayed Y: " << grid->_cells_displayed_y << "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
            }

          break;

          case SDLK_DOWN:
            //if(first_y+(16-(first_y*2))<16){
            //std::cout<<"first: " << first_x <<" num_cells_displayed: " << cells_displayed << "  result of formula: " << (first_y   + (16-(first_y*2))        ) << std::endl;
            //if((first_y   + (16-(first_y*2))        )   <     16){
            //if((grid->_first_y   + grid->_cells_displayed        )   <     grid->_num_cells){
            if((grid->_first_y   + grid->_cells_displayed_y        )   <     grid->_num_cells_y){   //Agosto 3
              grid->_first_y++;
              //std::cout<<"DOWN***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y<<" num_cells_displayed: " << grid->_cells_displayed << "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
              std::cout<<"DOWN***  First X: " << grid->_first_x << "  First Y: " << grid->_first_y <<" num_cells_displayed X: " << grid->_cells_displayed_x << " num_cells_displayed Y: " << grid->_cells_displayed_y << "  Height: "<< Cell::_height << "  Width: " <<Cell::_width  << std::endl;
            }

          break;

          case SDLK_j:
            if(target_refresh > lower_limit)
              target_refresh = target_refresh/2;
          break;

          case SDLK_k:
            if(target_refresh < upper_limit)
              target_refresh = target_refresh*2;
          break;
      }
    }
    //cell->handleEvent(&e);
    /*for(auto &i : grid)
      for(auto j : i)
      //grid[i][j] = handleEventCoordinate(i, j, &e);
        j->handleEvent(&e);
    */
   //Una variable que te diga cuales se van a desplegar de todas las que hay
    /*for (auto i : grid)
      i->handleEvent(&e);

    */
      /*
      for (auto i : grid){
        if((i->_pos.x>=first_x)&&(i->_pos.x<(16-first_x)))
          if((i->_pos.y>=first_y)&&(i->_pos.y<(16-first_y)))
            i->handleEvent(&e, first_x, first_y);
      }
      */

     /// AGosto 3
     /*
      for (auto i : grid->_the_grid){
        if((i->_pos.x>=grid->_first_x)&&(i->_pos.x<(grid->_first_x+grid->_cells_displayed)))
          if((i->_pos.y>=grid->_first_y)&&(i->_pos.y<(grid->_first_y+grid->_cells_displayed)))
            i->handleEvent(&e, grid->_first_x, grid->_first_y);
      }
      */
      
      for (auto i : grid->_the_grid){
        if((i->_pos.x>=grid->_first_x)&&(i->_pos.x<(grid->_first_x+grid->_cells_displayed_x)))
          if((i->_pos.y>=grid->_first_y)&&(i->_pos.y<(grid->_first_y+grid->_cells_displayed_y)))
            i->handleEvent(&e, grid->_first_x, grid->_first_y);
      }
      

      ///

  }
}
void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }
}