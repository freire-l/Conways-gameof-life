#include <iostream>
#include "utils.h"
#include "grid.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"

//Initialize Static Variables

    //Initial height and width of cells to be displayed
    int Cell::_height = kScreen_height/kInitial_display_cell_y; 
    int Cell::_width = kScreen_width/kInitial_display_cell_x;

    //Initial number of cells displayed in both axis
    int Grid::_cells_displayed_x = kInitial_display_cell_x;
    int Grid::_cells_displayed_y = kInitial_display_cell_y;

    //Initial offset of the grid in both axis
    int Grid::_offset_x = kInitial_offset_x;
    int Grid::_offset_y = kInitial_offset_y;

    //Initial offset of the grid, in the x axis
    int Grid::_max_zoom_out = kMax_zoom_out_x;

    //Coordinate of the first cell to be displayed, on the upper left corner

    //int Grid::_first_x = 80-1;
    //int Grid::_first_y = 40-1;

    //int Grid::_first_x = 240-1;
    //int Grid::_first_y = 120-1;

    int Grid::_first_x = (kNum_cells_x/3)-1; //240
    int Grid::_first_y = (kNum_cells_y/3)-1; //120

    //int Grid::_first_x = 720-1;
    //int Grid::_first_y = 360-1;


//main compatible with multiple SDL platforms
int main( int argc, char* args[] ) {

  Renderer renderer(kScreen_width, kScreen_height);

  Controller controller;

  Game game(kScreen_width, kScreen_height);

  game.Run(controller, renderer);

  std::cout << "Game has terminated successfully!\n";
  return 0;
}