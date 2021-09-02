#include "game.h"
#include "utils.h"
#include <iostream>
#include "SDL.h"


///

  //Agosto 3
/*
Game::Game(int size_grid): _size_grid(size_grid){

  _actual_grid = new Grid(_num_cells, _size_grid);
  _next_grid   = new Grid(_num_cells, _size_grid);
}
*/


Game::Game(int width_grid, int height_grid): _width_grid(width_grid), _height_grid(height_grid){
  _actual_grid = new Grid(kNum_cells_x, kNum_cells_y, _width_grid, _height_grid);
  _next_grid   = new Grid(kNum_cells_x, kNum_cells_y, _width_grid, _height_grid);
}

//31 agosto
/*
     std::vector <std::thread> threads;
      for (auto i : grid->_the_grid){
        threads.push_back(std::thread(DrawCell, i, grid));
      }

      for (auto &t : threads){
        t.join();
      }
*/

void Game::Update_cells_wrapper(Game* game, Cell *i){
  game->Update_cells(i);
}

void Game::Update_cells(Cell *i){
        int sum = _actual_grid->Count_Nhbr(i);
        bool is_alive = false;
        bool new_live = false;
        //update value of next "point"

        //accessing the array
        is_alive = (_actual_grid->_the_grid)[i->_index]->check_life();
        //conditions to game of life
        if(is_alive){
          if(sum<=1 || sum>=4){
            new_live = false;
            //(_next_grid->_the_grid)[i->_index]->set_life(false);
            //std::cout<<"A ******************************* ";
            }
          else if(sum == 2 || sum ==3){
            new_live = true;
            //(_next_grid->_the_grid)[i->_index]->set_life(true);
            //std::cout<<"B ******************************** ";
            }
          else {
            new_live = false;
            //(_next_grid->_the_grid)[i->_index]->set_life(false);
            //std::cout<<"F ******************************* ";
          }

        }else{
          if(sum ==3){
            new_live = true;
            //(_next_grid->_the_grid)[i->_index]->set_life(true);
            //std::cout<<"C *********************************** ";
          } else{
            new_live = false;
            //(_next_grid->_the_grid)[i->_index]->set_life(false);
            //std::cout<<"F ******************************* ";
          }
        }
        //writing to array
        (_next_grid->_the_grid)[i->_index]->set_life(new_live);

        //possible reasons:
        //data race, creating to many threads
}
///

void Game::Update_next_grid(){
      auto point = _next_grid->_the_grid;

      //std::vector <std::thread> threads;/////
      for (auto i : _actual_grid->_the_grid){

            //threads.push_back(std::thread(Game::Update_cells_wrapper, this, i));//////
            Update_cells(i);
      }

        //Multithreading
        /*
          for (auto &t : threads){
            t.join();
          }
        */

}

void Game::Run(Controller const &controller, Renderer &renderer){
    bool is_running = true;
    Uint32 target_frame = kFramesPerSecond;
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    Uint32 target_refresh = 1024;    


    while (is_running) {
  
      frame_start = SDL_GetTicks();
  
      // Input, Update, Render - the main game loop.

      
      controller.HandleInput2(is_running, _actual_grid, target_refresh, go, step);
                  //Update();
      renderer.Render2(_actual_grid);

      frame_end = SDL_GetTicks();

      // Keep track of how long each loop through the input/update/render cycle
      // takes.
      frame_count++;
      frame_duration = frame_end - frame_start;
      //std::cout << "frame duration" << frame_duration << std::endl;

      // After every second, update the window title.
      if(go==true || step == true){
          if ((frame_end - title_timestamp >= target_refresh) || (go == false && step == true)) {

            Update_next_grid();

            Grid* aux =  new Grid(0,0,0,0);
            aux =  _actual_grid;
            _actual_grid = _next_grid;
            _next_grid = aux;
            aux = NULL;
              delete(aux);


            frame_count = 0;
            title_timestamp = frame_end;

          }
              if (step == true)
                step = false;
      }

      if (frame_duration < target_frame) {
        SDL_Delay(target_frame - frame_duration);
        //std::cout << "waiting" << std::endl;
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