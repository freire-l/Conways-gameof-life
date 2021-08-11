#ifndef GRID_H
#define GRID_H

#include <random>
#include "SDL.h"
#include "controller.h"

#include "cell.h"

class Grid{

    public:
        //Grid(int num_cells, int size_grid, int first_cell);
        ///Agosto 3
        //Grid(int num_cells, int size_grid);
        Grid(int num_cells, int size_grid, int width_grid, int height_grid);
        ///
        int Count_Nhbr(Cell* the_cell); 

//25 jul

///
        //agosto 3
        //static int _cells_displayed;

        static int _cells_displayed_x;
        static int _cells_displayed_y;

///

        static int _max_zoom_out;

        static int _first_x;
        static int _first_y;

    private:
        std::vector<Cell*> _the_grid;

///
        //Agosto 3
        //int _size_grid;
        //int _num_cells;

        
        int _num_cells_x = 60;
        int _num_cells_y = 40;

        int _width_grid;
        int _height_grid;
        
///

/*25 jul
        int _cells_displayed = 16;

        int _max_zoom_out = 32;

        int _first_x;
        int _first_y;

*/


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