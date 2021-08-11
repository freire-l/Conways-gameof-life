#include <iostream>
#include "utils.h"
#include "grid.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"


    //int Cell::_height = 640/16;
    //int Cell::_width = 640/16;

///
  //Agosto 3
    //int Cell::_height = kScreenSize/initial_display_cell;
    //int Cell::_width = kScreenSize/initial_display_cell;

    int Cell::_height = kScreenHeight/initial_display_cell_y; //descom
    int Cell::_width = kScreenWidth/initial_display_cell_x;

///

///
    //agosto 3
    //int Grid::_cells_displayed = 40;

    int Grid::_cells_displayed_x = 60;
    int Grid::_cells_displayed_y = 40;


///

    int Grid::_max_zoom_out = 52;

    int Grid::_first_x = 0;
    int Grid::_first_y = 0;




    //este 16 es el que puede variar seg[un el numero de celdas que quieras desplegar

//main compatible with multiple SDL platforms
int main( int argc, char* args[] ) {


  //Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);

///
  //Agosto 3
  //Renderer renderer(kScreenSize, kScreenSize);

  Renderer renderer(kScreenWidth, kScreenHeight);

///
  Controller controller;
  //Game game(kGridWidth, kGridHeight);

    //int Cell::_height = _size_grid/_num_cells;
    //int Cell::_width = _size_grid/_num_cells;


  //std::cout<<"one"<<std::endl;
  //**********************Este 16 siempre debe ser el maximo
  //Grid grid(16,640);

///
  //Agosto 3
  //Game game(kScreenSize);
  Game game(kScreenWidth, kScreenHeight);

///
  //std::cout<<"one"<<std::endl;
  //grid.Run(controller, renderer);
  game.Run(controller, renderer);
  //std::cout<<"two"<<std::endl;
  //game.Run(controller, renderer, kMsPerFrame);
  //std::cout << "Game has terminated successfully!\n";
  //std::cout << "Score: " << game.GetScore() << "\n";
  //std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}