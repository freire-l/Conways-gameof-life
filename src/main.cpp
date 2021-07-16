#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "grid.h"

    int Cell::_height = 640/16;
    int Cell::_width = 640/16;

//main compatible with multiple SDL platforms
int main( int argc, char* args[] ) {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  //Game game(kGridWidth, kGridHeight);

    //int Cell::_height = _size_grid/_num_cells;
    //int Cell::_width = _size_grid/_num_cells;


  std::cout<<"one"<<std::endl;
  Grid grid(16,640);
  std::cout<<"one"<<std::endl;
  grid.Run(controller, renderer);
  std::cout<<"two"<<std::endl;
  //game.Run(controller, renderer, kMsPerFrame);
  //std::cout << "Game has terminated successfully!\n";
  //std::cout << "Score: " << game.GetScore() << "\n";
  //std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}