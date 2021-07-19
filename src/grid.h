#ifndef GRID_H
#define GRID_H

#include <random>
#include "SDL.h"
#include "controller.h"

#include "cell.h"

class Grid{

    public:
        Grid(int num_cells, int size_grid, int first_cell);
        int Count_Nhbr(Cell* the_cell); 

    private:
        std::vector<Cell*> _the_grid;
        int _size_grid;
        int _num_cells;

        int _cells_displayed = 16;

        int _max_zoom_out = 32;

        int _first_x;
        int _first_y;


        friend class Controller;
        friend class Renderer;
        friend class Game;

};


//***********************************************************************
//***********************************************************************
/*
class Grid{

    public:
    Grid(int num_cells, int size_grid);
    ~Grid(){};
    void Run(Controller const &controller, Renderer &renderer);

    int first_x = 0;
    int first_y = 0;

    int cells_displayed = 16;
    

    private:
        Cell* _cell;
        //std::vector<std::vector<Cell*>> _the_grid;
        //std::vector<std::vector<int>> _the_grid;
        std::vector<Cell*> _the_grid;
        int _size_grid;
        int _num_cells;

};
*/

#endif