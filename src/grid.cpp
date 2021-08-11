#include <iostream>
#include "SDL.h"
#include "grid.h"

//Grid::Grid(int num_cells, int size_grid, int first_cell): _num_cells(num_cells), _size_grid(size_grid), _first_x(first_cell) , _first_y(first_cell){
///
  //Agosto 3

/*
Grid::Grid(int num_cells, int size_grid): _num_cells(num_cells), _size_grid(size_grid){
  int x;
  int y;
  _the_grid.reserve(_num_cells*_num_cells);
  for(int i = 0; i < (_num_cells*_num_cells); ++i)
    {
      x = (i%_num_cells);
      y = (i/_num_cells);
      _the_grid.push_back(new Cell(x, y, i));
    }
}
*/

Grid::Grid(int num_cells_x, int num_cells_y, int width_grid, int height_grid): _num_cells_x(num_cells_x), _num_cells_y(num_cells_y), _width_grid(width_grid), _height_grid(height_grid){

  int x;
  int y;
  _the_grid.reserve(_num_cells_x*_num_cells_y);
  for(int i = 0; i < (_num_cells_x*_num_cells_y); ++i)
    {
      x = (i%_num_cells_x);
      y = (i/_num_cells_x);
      _the_grid.push_back(new Cell(x, y, i));
    }
}
///

int Grid::Count_Nhbr(Cell* the_cell){
  int sum = 0;
  auto x = (the_cell->_pos).x;
  auto y = (the_cell->_pos).y;
  //std::cout<<"Vecinos: ";
  //count top left
  //if((((the_cell->_pos).x) > 0 )&&(((the_cell->_pos).y) > 0 )){
  if( x>0 && y>0 ){
    //std::cout<<"a**"<<" x: "<<x<<" y: "<<y<<std::endl;
    //if(_the_grid[(the_cell->_index)-_num_cells-1]->_is_alive == true){
    //Agosto 3 
    if(_the_grid[(the_cell->_index)-_num_cells_x-1]->_is_alive == true){
      //std::cout<<"TOp left ";
        sum++;
    }

  } 
  //count top
  if(y>0){
    //std::cout<<"b**"<<" x: "<<x<<" y: "<<y<<std::endl;
    //if(_the_grid[(the_cell->_index)-_num_cells]->_is_alive == true){
    //Agosto 3 
    if(_the_grid[(the_cell->_index)-_num_cells_x]->_is_alive == true){
      //std::cout<<"Top ";
      sum++;   
    } 
  }

  //count top right
  //if( y>0 && x<(_num_cells-1) ){
  //Agosto 3 
  if( y>0 && x<(_num_cells_x-1) ){
        //std::cout<<"c**"<<" x: "<<x<<" y: "<<y<<std::endl;
    //if(_the_grid[(the_cell->_index)-_num_cells+1]->_is_alive == true){
    //Agosto 3 
    if(_the_grid[(the_cell->_index)-_num_cells_x+1]->_is_alive == true){
          //std::cout<<"Top Right ";
      sum++;
    }
  } 
  //count right   ***************************This one is wrong, should be x < _num_cells-1
  //if(x<(_num_cells-1)){
  //Agosto 3 
  if(x<(_num_cells_x-1)){
        //std::cout<<"d**"<<" x: "<<x<<" y: "<<y<<std::endl;
    if(_the_grid[(the_cell->_index)+1]->_is_alive == true){
      //std::cout<<"Right ";
      sum++; 
    }   
  }
  //count bottom right
  //if(y<(_num_cells-1) && x<(_num_cells-1)){
  //Agosto 3 
  if(y<(_num_cells_y-1) && x<(_num_cells_x-1)){
        //std::cout<<"e**"<<" x: "<<x<<" y: "<<y<<std::endl;
    //if(_the_grid[(the_cell->_index)+_num_cells+1]->_is_alive == true){
    //Agosto 3 
    if(_the_grid[(the_cell->_index)+_num_cells_x+1]->_is_alive == true){
      //std::cout<<"Bottom right ";
      sum++;   
    } 
  }
  //count bottom
  //if(y<(_num_cells-1)){
  //Agosto 3 
  if(y<(_num_cells_y-1)){
        //std::cout<<"f**"<<" x: "<<x<<" y: "<<y<<std::endl;
    //if(_the_grid[(the_cell->_index)+_num_cells]->_is_alive == true){
    //Agosto 3 
    if(_the_grid[(the_cell->_index)+_num_cells_x]->_is_alive == true){
      //std::cout<<"Bottom ";
      sum++;    
    }
  }
  //count bottom left
  //if( x>0 && y<(_num_cells-1) ){
  //Agosto 3 
  if( x>0 && y<(_num_cells_y-1) ){
        //std::cout<<"g**"<<" x: "<<x<<" y: "<<y<<std::endl;
    //if(_the_grid[(the_cell->_index)+_num_cells-1]->_is_alive == true){
    //Agosto 3 
    if(_the_grid[(the_cell->_index)+_num_cells_x-1]->_is_alive == true){
      //std::cout<<"Bottom left ";
      sum++;
    }
  } 
  //count left
  if(x>0){
        //std::cout<<"h**"<<" x: "<<x<<" y: "<<y<<std::endl;
    if(_the_grid[(the_cell->_index)-1]->_is_alive == true){
      //std::cout<<"Left";
      sum++; 
       //std::cout<<"i**"<<std::endl;
    }
   
  }

  //std::cout<<std::endl;

  return sum;

}

//***************************************************************************************
//***************************************************************************************

/*
//Grid::Grid(int num_cells, int size_grid): _num_cells(num_cells), _size_grid(size_grid), _the_grid(num_cells,std::vector<int>(num_cells, 0)){
Grid::Grid(int num_cells, int size_grid): _num_cells(num_cells), _size_grid(size_grid) {
  //int size_cell = size_grid/num_cells;
  int x;
  int y;
  _the_grid.reserve(_num_cells);
  for(int i = 0; i < (_num_cells*_num_cells); ++i)
    {
      //x = ((i%_num_cells)*(Cell::_width));
      //y = ((i/_num_cells)*(Cell::_height));

      x = (i%_num_cells);
      y = (i/_num_cells);
      std::cout<<"one1"<<std::endl;
      _the_grid.push_back(new Cell(x, y));
      std::cout<<"one2 "<< x << " " << y << " "<<std::endl;
    }

}

//Grid::~Grid()

void Grid::Run(Controller const &controller, Renderer &renderer){

    bool is_running = true;
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    Uint32 target_refresh = 1024;    

    //_cell = new Cell(100, 100, 100, 100);
    //_cell->setter_Pos(100,100);

  while (is_running) {
    //frame_start = SDL_GetTicks();
    frame_start = SDL_GetTicks();
 
     // Input, Update, Render - the main game loop.
    //controller.HandleInput(running, snake);
    //controller.HandleInput2(is_running, _the_grid, _num_cells, _size_grid, _cell);
    controller.HandleInput2(is_running, _the_grid, first_x, first_y, cells_displayed, target_refresh);
    //Update();
    //renderer.Render(snake, food);
    //renderer.Render2(_cell);
    renderer.Render2(_the_grid, first_x, first_y, cells_displayed);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= target_refresh) {
      //renderer.UpdateWindowTitle(score, frame_count);
      //std::cout<< "Este mensaje ocurre cada " << target_refresh << " segundos"<<std::endl;
      frame_count = 0;
      title_timestamp = frame_end;
    }
  }
}
*/

