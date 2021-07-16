#ifndef GRID_H
#define GRID_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "cell.h"


class Grid{

    public:
    Grid(int num_cells, int size_grid);
    ~Grid(){};
    void Run(Controller const &controller, Renderer &renderer);

    private:
        Cell* _cell;
        //std::vector<std::vector<Cell*>> _the_grid;
        //std::vector<std::vector<int>> _the_grid;
        std::vector<Cell*> _the_grid;
        int _size_grid;
        int _num_cells;

};

#endif