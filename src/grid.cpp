#include <iostream>
#include "SDL.h"
#include "grid.h"

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
    }
}


int Grid::Count_Nhbr(Cell* the_cell){
  int sum = 0;
  auto x = (the_cell->_pos).x;
  auto y = (the_cell->_pos).y;

  //count top left
  if( x>0 && y>0 ){
    if(_the_grid[(the_cell->_index)-_num_cells_x-1]->_is_alive == true){
        sum++;
    }

  } 
  //count top
  if(y>0){
    if(_the_grid[(the_cell->_index)-_num_cells_x]->_is_alive == true){
      sum++;   
    } 
  }
  //count top right
  if( y>0 && x<(_num_cells_x-1) ){
    if(_the_grid[(the_cell->_index)-_num_cells_x+1]->_is_alive == true){
      sum++;
    }
  } 
  //count right  
  if(x<(_num_cells_x-1)){
    if(_the_grid[(the_cell->_index)+1]->_is_alive == true){
      sum++; 
    }   
  }
  //count bottom right
  if(y<(_num_cells_y-1) && x<(_num_cells_x-1)){
    if(_the_grid[(the_cell->_index)+_num_cells_x+1]->_is_alive == true){
      sum++;   
    } 
  }
  //count bottom
  if(y<(_num_cells_y-1)){
    if(_the_grid[(the_cell->_index)+_num_cells_x]->_is_alive == true){
      sum++;    
    }
  }
  //count bottom left
  if( x>0 && y<(_num_cells_y-1) ){
    if(_the_grid[(the_cell->_index)+_num_cells_x-1]->_is_alive == true){
      sum++;
    }
  } 
  //count left
  if(x>0){
    if(_the_grid[(the_cell->_index)-1]->_is_alive == true){
      sum++;
    } 
  }
  return sum;

}

