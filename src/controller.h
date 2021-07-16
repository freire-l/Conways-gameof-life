#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "cell.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake) const;
  //void HandleInput2(bool &running, std::vector<std::vector<Cell*>> grid, Cell* cell) const;
  void HandleInput2(bool &running, std::vector<Cell*> grid) const;
  //void HandleInput2(bool &running, std::vector<std::vector<int> grid, int num_cells, int size_grid, Cell* cell) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif