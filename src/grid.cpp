#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "SDL.h"
#include "grid.h"

//****************************************************//
//*****         Grid Class Constructor          ******//
//****************************************************//
Grid::Grid(int num_cells_x, int num_cells_y, int width_grid, int height_grid): 
                          _num_cells_x(num_cells_x), _num_cells_y(num_cells_y), 
                          _width_grid(width_grid), _height_grid(height_grid){
  int x;
  int y;
  _the_grid.reserve(_num_cells_x*_num_cells_y);   //Reserving the space for all the cell objects the grid is going to need

  for(int i = 0; i < (_num_cells_x*_num_cells_y); ++i)     //traversing trough the array pushing newly created cell Objects
    {
      x = (i%_num_cells_x);                   //Computing the corresponsing x coordinate
      y = (i/_num_cells_x);                   //Computing the corresponding y coordinate
      _the_grid.push_back(new Cell(x, y, i)); //Pushing back a Cell with the corresponding x and y coordinates, and the index in the grid array
      //_the_grid.push_back(std::make_shared<Cell> (x, y, i)); //Pushing back a Cell with the corresponding x and y coordinates, and the index in the grid array
    }
}

//****************************************************//
//*****         Grid Class Destructor           ******//
//****************************************************//
Grid::~Grid(){
  for (auto i : _the_grid){
    delete i;
  }

  _the_grid.clear();
}

//****************************************************//
//*****         Grid Copy Assignment            ******//
//****************************************************//
Grid &Grid::operator=(const Grid &source){
  if (this == &source){
    return *this;
  }
  /*for (auto i : _the_grid){
    delete i;
  }*/

  _the_grid = source._the_grid;

  _num_cells_x = source._num_cells_x;
  _num_cells_y = source._num_cells_y;

  _width_grid = source._width_grid;
  _height_grid= source._height_grid;
  return *this;
}
void Grid::Fill_Grid(int select){
  std::cout << "***** Filling Grid ********"<<std::endl;
  //fill values for clearing
  switch (select){
    case 0:
      for (auto i : _the_grid){
        i->set_life(false);
      }
    break;

    case 1:
        std::string line;
        std::vector <int> parse;
        std::string value;

        std::ifstream stream("../src/demonoid.txt");
        if (stream.is_open()) {
          while(std::getline(stream, line)){
            std::replace(line.begin(), line.end(), ',', ' ');
            std::istringstream linestream(line);
            //fill out the vector with values parsed from the line
            while (linestream >> value)
            {
              parse.push_back(std::stoi(value));
            }
          }
        }

        int traverse = 0;
        for (auto i : _the_grid){
          //std::cout << "***** Filling Grid  4  ********"<<std::endl;
          if(((i->_pos.x>=_first_x)&&(i->_pos.x<(_first_x+_cells_displayed_x)))&&((i->_pos.y>=_first_y)&&(i->_pos.y<(_first_y+_cells_displayed_y)))){
              if(parse[traverse] == 0)
                i->set_life(false);
              else
                i->set_life(true);
              traverse++;
          }
        }
    break;
  }
  //if 1, fill the values for 1
}

void Grid::Reset_Grid_Scope(){
    //Initial height and width of cells to be displayed
    Cell::_height = kScreen_height/kInitial_display_cell_y; 
    Cell::_width = kScreen_width/kInitial_display_cell_x;

    //Initial number of cells displayed in both axis
    Grid::_cells_displayed_x = kInitial_display_cell_x;
    Grid::_cells_displayed_y = kInitial_display_cell_y;

    //Initial offset of the grid in both axis
    Grid::_offset_x = kInitial_offset_x;
    Grid::_offset_y = kInitial_offset_y;

    //Coordinate of the first cell to be displayed, on the upper left corner
    Grid::_first_x = (kNum_cells_x/3)-1; //240
    Grid::_first_y = (kNum_cells_y/3)-1; //120
}

//****************************************************//
//*****         Count Neighbors Method          ******//
//****************************************************//
int Grid::Count_Nhbr(Cell* the_cell){
//int Grid::Count_Nhbr(std::shared_ptr <Cell> the_cell){
  int sum = 0;
  auto x = (the_cell->_pos).x;                            //  Get the x and y coordinates
  auto y = (the_cell->_pos).y;

  //Check neighbors all around the cell, if neghbr is alive, add one to the count

  //count top left
  if( x>0 && y>0 ){                                       //  Count top left nghbr only if we are not in the top left of the grid
    if(_the_grid[(the_cell->_index)-_num_cells_x-1]->_is_alive == true){
        sum++;
    }
  } 
  //count top
  if(y>0){                                                //  Count top nghbr only if we are not on top of the grid
    if(_the_grid[(the_cell->_index)-_num_cells_x]->_is_alive == true){
      sum++;   
    } 
  }
  //count top right
  if( y>0 && x<(_num_cells_x-1) ){                        //  Count Top right nghbr only if we are are not on top right of the grid
    if(_the_grid[(the_cell->_index)-_num_cells_x+1]->_is_alive == true){
      sum++;
    }
  } 
  //count right                                           //  Count right nghbr only if we are are not right of the grid 
  if(x<(_num_cells_x-1)){
    if(_the_grid[(the_cell->_index)+1]->_is_alive == true){
      sum++; 
    }   
  }
  //count bottom right                                    //  Count bottom right nghbr only if we are are not on top right of the grid
  if(y<(_num_cells_y-1) && x<(_num_cells_x-1)){
    if(_the_grid[(the_cell->_index)+_num_cells_x+1]->_is_alive == true){
      sum++;   
    } 
  }
  //count bottom                                          //  Count bottom nghbr only if we are are not on the bottom of the grid
  if(y<(_num_cells_y-1)){
    if(_the_grid[(the_cell->_index)+_num_cells_x]->_is_alive == true){
      sum++;    
    }
  }
  //count bottom left                                     //  Count bottom left nghbr only if we are are not on the bottom left corner of the grid
  if( x>0 && y<(_num_cells_y-1) ){
    if(_the_grid[(the_cell->_index)+_num_cells_x-1]->_is_alive == true){
      sum++;
    }
  } 
  //count left                                            //  Count left nghbr only if we are are not on the left of the grid
  if(x>0){
    if(_the_grid[(the_cell->_index)-1]->_is_alive == true){
      sum++;
    } 
  }
  return sum;

}

