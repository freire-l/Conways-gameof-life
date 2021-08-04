#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(int size_grid): _size_grid(size_grid){
  //25 jul /*
  //_actual_grid = new Grid(_num_cells, _size_grid, _first_cell);
  //_next_grid   = new Grid(_num_cells, _size_grid, _first_cell);
  //25jul */

  _actual_grid = new Grid(_num_cells, _size_grid);
  _next_grid   = new Grid(_num_cells, _size_grid);
}

void Game::Update_next_grid(){
      auto point = _next_grid->_the_grid;
      for (auto i : _actual_grid->_the_grid){
        //count live neighbors of actual "i"
        //std::cout<<"G**"<<std::endl;
        int sum = _actual_grid->Count_Nhbr(i);

        //update value of next "point"
        //conditions to game of life
        if((_actual_grid->_the_grid)[i->_index]->check_life()){
          if(sum<=1 || sum>=4){
            (_next_grid->_the_grid)[i->_index]->set_life(false);
            //std::cout<<"A ******************************* ";
            }
          else if(sum == 2 || sum ==3){
            (_next_grid->_the_grid)[i->_index]->set_life(true);
            //std::cout<<"B ******************************** ";
            }
          else {
            (_next_grid->_the_grid)[i->_index]->set_life(false);
            //std::cout<<"F ******************************* ";
          }

        }else{
          if(sum ==3){
            (_next_grid->_the_grid)[i->_index]->set_life(true);
            //std::cout<<"C *********************************** ";
          } else{
            (_next_grid->_the_grid)[i->_index]->set_life(false);
            //std::cout<<"F ******************************* ";
          }
        }
        //std::cout<<std::endl;
        //std::cout<<"Cell Index: "<<i->_index<< "  X: "<< (i->get_x()) << "  Y: "<< (i->get_y()) << "  Neighb:" << sum << std::endl;
        //if((_next_grid->_the_grid)[i->_index]->check_life())
          //std::cout<<"La siguiente est[a viva"<<std::endl;
        //else
          //std::cout<<"La siguiente est[a muerta"<<std::endl;

      }

}

void Game::Run(Controller const &controller, Renderer &renderer){
    bool is_running = true;
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    Uint32 target_refresh = 1024;    


    while (is_running) {
  
      frame_start = SDL_GetTicks();
  
      // Input, Update, Render - the main game loop.

      //controller.HandleInput2(is_running, _the_grid, first_x, first_y, cells_displayed, target_refresh);
      controller.HandleInput2(is_running, _actual_grid, target_refresh, go, step);
      //Update();
      renderer.Render2(_actual_grid);

      frame_end = SDL_GetTicks();

      // Keep track of how long each loop through the input/update/render cycle
      // takes.
      frame_count++;
      frame_duration = frame_end - frame_start;

      //std::cout<<"A**"<<std::endl;
      // After every second, update the window title.
      if(go==true || step == true){
          if ((frame_end - title_timestamp >= target_refresh) || (go == false && step == true)) {
            //update next_grid
            //std::cout<<"B**"<<std::endl;
            Update_next_grid();
            //make next grid the actual grid
              //std::cout<<"C**"<<std::endl;
            //25 jul //Grid* aux =  new Grid(0,0,0);
            Grid* aux =  new Grid(0,0);
            aux =  _actual_grid;
              //std::cout<<"D**"<<std::endl;
            _actual_grid = _next_grid;
              //std::cout<<"E**"<<std::endl;
            _next_grid = aux;
              //std::cout<<"F**"<<std::endl;
              aux = NULL;

              delete(aux);

            //delete(aux);

            frame_count = 0;
            title_timestamp = frame_end;

          }
              if (step == true)
                step = false;
      }
    }
}



//*********************************************************************
//*********************************************************************

/*
Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

*/