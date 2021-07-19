#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "cell.h"
#include "grid.h"

class Grid;

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake) const;
  //void HandleInput2(bool &running, std::vector<std::vector<Cell*>> grid, Cell* cell) const;
  //void HandleInput2(bool &running, std::vector<Cell*> grid, int &limit_x, int &limit_y, int &cells_displayed, Uint32 &target_refresh) const;
  void HandleInput2(bool &running, Grid* grid, Uint32 &target_refresh) const;
  //void HandleInput2(bool &running, std::vector<std::vector<int> grid, int num_cells, int size_grid, Cell* cell) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif