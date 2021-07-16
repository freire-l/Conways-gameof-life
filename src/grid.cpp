#include <iostream>
#include "SDL.h"
#include "grid.h"

//Grid::Grid(int num_cells, int size_grid): _num_cells(num_cells), _size_grid(size_grid), _the_grid(num_cells,std::vector<int>(num_cells, 0)){
Grid::Grid(int num_cells, int size_grid): _num_cells(num_cells), _size_grid(size_grid) {
  //int size_cell = size_grid/num_cells;
  int x;
  int y;
  _the_grid.reserve(_num_cells);
  for(int i = 0; i < (_num_cells*_num_cells); ++i)
    {
      x = ((i%_num_cells)*(Cell::_width));
      y = ((i/_num_cells)*(Cell::_height));
      std::cout<<"one1"<<std::endl;
      _the_grid.push_back(new Cell(x, y));
      std::cout<<"one2 "<< x << " " << y << " "<<std::endl;
    }
  
  
  /*
  int size_cell = size_grid/num_cells;
  _the_grid.reserve(_num_cells);
  for(int i = 0; i < num_cells; ++i)
  {
    _the_grid.push_back()
    _the_grid[i].reserve(num_cells);

    for (int j = 0; j < num_cells ; ++j)
    {
      //Cell* cell_ptr = new Cell(i*size_cell, j*size_cell, size_cell, size_cell);
      std::cout<<"one1"<<std::endl;
      _the_grid[i].push_back(new Cell(i*size_cell, j*size_cell, size_cell, size_cell));
      std::cout<<"one2"<<std::endl;
    }
  }*/
}
//Grid::~Grid()

void Grid::Run(Controller const &controller, Renderer &renderer){

    bool is_running = true;


    //_cell = new Cell(100, 100, 100, 100);
    //_cell->setter_Pos(100,100);

  while (is_running) {
    //frame_start = SDL_GetTicks();
    
     // Input, Update, Render - the main game loop.
    //controller.HandleInput(running, snake);
    //controller.HandleInput2(is_running, _the_grid, _num_cells, _size_grid, _cell);
    controller.HandleInput2(is_running, _the_grid);
    //Update();
    //renderer.Render(snake, food);
    //renderer.Render2(_cell);
    renderer.Render2(_the_grid);
  }
}