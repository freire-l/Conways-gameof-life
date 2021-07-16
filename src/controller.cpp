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
void Controller::HandleInput2(bool &running, std::vector<Cell*> grid) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    }
    //cell->handleEvent(&e);
    /*for(auto &i : grid)
      for(auto j : i)
      //grid[i][j] = handleEventCoordinate(i, j, &e);
        j->handleEvent(&e);
    */
    for (auto i : grid)
      i->handleEvent(&e);

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