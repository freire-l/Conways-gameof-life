#ifndef GRID_H
#define GRID_H


#include "SDL.h"
#include "controller.h"
#include "utils.h"
#include "cell.h"

class Grid{

    public:

        Grid(int num_cells_x, int num_cells_y, int width_grid, int height_grid);            //  Constructor for Grid Class, takes the sizes in pixels of 
                                                                                            //  both axis of the screen to be created,
                                                                                            //  and the number of cells of both axis of the grid.
                                                                                            //  Creates the grid by initializing an array of Cell objects

        ~Grid();

        Grid &operator=(const Grid &source);

        void Fill_Grid(int select);

        void Reset_Grid_Scope();
        
        int Count_Nhbr(Cell* the_cell);                                                     //  Method that counts the live neighbors a cell has
        //int Count_Nhbr(std::shared_ptr <Cell> the_cell);                                                     //  Method that counts the live neighbors a cell has

        static int _cells_displayed_x;
        static int _cells_displayed_y;

        static int _max_zoom_out;
        static int _max_zoom_in;

        static int _first_x;
        static int _first_y;

        static int _offset_x;
        static int _offset_y;

    private:
        std::vector<Cell*> _the_grid;      //Array of Cell Objects, representing the grid
        //std::vector<std::shared_ptr<Cell>> _the_grid;      //Array of Cell Objects, representing the grid
        int _num_cells_x;                  //Number of cells in the grid, on the x axis
        int _num_cells_y;                  //Number of cells in the grid, on the y axis

        int _width_grid;                  //Number of pixels for screen width
        int _height_grid;                 //Number of pixels for screen height

        friend class Controller;
        friend class Renderer;
        friend class Game;

};

#endif