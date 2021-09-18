#include "game.h"
#include "utils.h"
#include <iostream>
#include "SDL.h"

//****************************************************//
//*****         Game Class Constructor          ******//
//****************************************************//

Game::Game(int width_grid, int height_grid): _width_grid(width_grid), _height_grid(height_grid){
  //Creating actual grid and next grid, both with the same dimentions
  _actual_grid = std::make_shared<Grid>(kNum_cells_x, kNum_cells_y, _width_grid, _height_grid);
  _next_grid   = std::make_shared<Grid>(kNum_cells_x, kNum_cells_y, _width_grid, _height_grid);
}

//****************************************************//
//*****          Update a cell Method           ******//
//****************************************************//
void Game::Update_cell(Cell *i){  
//void Game::Update_cells(std::shared_ptr<Cell> i){
        int sum = _actual_grid->Count_Nhbr(i);              //  Count the number of neighbors the current cell has
        bool is_alive = false;
        bool new_live = false;

        //update value of next "point"
        //accessing the array. Access prottected
            std::unique_lock<std::mutex> lck (_mutex);
            is_alive = (_actual_grid->_the_grid)[i->_index]->check_life();   // checking is current cell is alive
            lck.unlock();

        //conditions to game of life
        if(is_alive){                                         //  Conditions if the cell is currently alive
          if(sum<=1 || sum>=4){ new_live = false; }

          else if(sum == 2 || sum ==3){ new_live = true; }

          else { new_live = false; }

        }else{                                                //  Conditions if the cell is currently dead
          if(sum ==3){ new_live = true; } 

          else{ new_live = false; }
        }

        //writing to array. Access protected
            lck.lock();
            (_next_grid->_the_grid)[i->_index]->set_life(new_live);         //setting the value of the cell for the next cycle
            lck.unlock();
}

//****************************************************//
//*****        Update several cells Method      ******//
//****************************************************//
void Game::Update_several_cells(int start, int end){
  for (int k = start; k<=end; k++){
    Update_cell(_actual_grid->_the_grid[k]);
  }
}

//****************************************************//
//*****   Update several cell wrapper Method    ******//
//****************************************************//
void Game::Update_several_wrapper(Game* game, int start, int end){
  game->Update_several_cells(start, end);
}

//****************************************************//
//*****         Update Next Grid Method         ******//
//****************************************************//
void Game::Update_next_grid(){
      //Control multithreading execution
      std::vector <std::thread> threads;

      int total_cells = kNum_cells_x*kNum_cells_y;
      
      threads.push_back(std::thread(Game::Update_several_wrapper, this, 0, (total_cells/2)-1));               //  Multithreading
      threads.push_back(std::thread(Game::Update_several_wrapper, this, total_cells/2, total_cells-1));       //  Multithreading
      
      for (auto &t : threads){
        t.join();
      }
}

//****************************************************//
//*****             Game Run Method             ******//
//****************************************************//

void Game::Run(Controller const &controller, Renderer &renderer){
    bool is_running = true;                        //Variable that controls wether the game is running or not

    //Variables that meassure time and help control the frame rate
    Uint32 target_frame = kFramesPerSecond;
    Uint32 start_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    Uint32 target_refresh = 1024;                  //Speed of grid update

    std::shared_ptr<Grid> aux = std::make_shared<Grid>(0,0,0,0);

    while (is_running) {                    //Main loop, controlled by is_running
  
      frame_start = SDL_GetTicks();         //Get time at the start of the loop
  
      // Game main loop Input, Update, Render - the main game loop.

      //**** Input   *********
      controller.HandleInput2(is_running, _actual_grid, _next_grid, target_refresh, go, step, skip_update);     //Method takes references to all game drivers, so they can be 
                                                                                       // affected by the input

      frame_end = SDL_GetTicks();            //Get current time

      // Keep track of how long each loop through the input/update/render cycle
      // takes.
      frame_count++;
      frame_duration = frame_end - frame_start;

      //******* Update *********
      // The Grid will be updated if "go" is active (Grid running)
      // or if a "step" of update is to be taken
      if(go==true || step == true){
          if ((frame_end - start_timestamp >= target_refresh) || (go == false && step == true)) {      //update if time passed matches the refresh rate

            //If HandleInput Methos has capture a file read, skip the normal update method
            if(skip_update !=true)
              Update_next_grid();     //Update the next grid based on the current grid values
            else
              skip_update = false;    //Reset Flag

            //Making the actual grid the nest grid by creating a temporary one
            //the memory form the axu grid is deleted afterwards
            
            aux =  _actual_grid;
            _actual_grid = _next_grid;
            _next_grid = aux;            

            //New start time
            start_timestamp = frame_end;

          }
          // Reset the step variable if it is active, so no more than one step is taken
          if (step == true){
            step = false;
          }
      }

      //******   Render   *********
      renderer.Render2(_actual_grid);

      //Stall execution if we are bellow the target farme duration
      if (frame_duration < target_frame) {
        SDL_Delay(target_frame - frame_duration);
      }
    }
}
