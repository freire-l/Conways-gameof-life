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

        ~Grid();                                                                            //  Grid Destructor

        Grid &operator=(const Grid &source);                                                //  Copy assigment

        bool Fill_Grid(int select);                                                         //  Method that fills the grid from a file corresponfing to the
                                                                                            //  "select" argument. eg. if select = 1, the method will be reading 
                                                                                            //  from figure1.txt.
                                                                                            //  Method returns true is the read was successful or false otherwise

        void Clear_Grid();                                                                  //  Method that clears the grid, setting all cells to dead state

        bool Store_Grid(int select);                                                        //  Method that stores the grid in a file corresponfing to the
                                                                                            //  "select" argument. eg. if select = 1, the method will be storing
                                                                                            //  the grid in a file named figure1.txt. If the file already exists
                                                                                            //  its content will be overwritten
                                                                                            //  Method returns true is the read was successful or false otherwise

        void Reset_Grid_Scope();                                                            //  Method that resets the position of the first cell displayed
                                                                                            //  and the zoom level to the original values
        
        int Count_Nhbr(Cell* the_cell);                                                     //  Method that counts the live neighbors a cell has

        static int _cells_displayed_x;
        static int _cells_displayed_y;

        static int _max_zoom_out;
        static int _max_zoom_in;

        static int _first_x;
        static int _first_y;

        static int _offset_x;
        static int _offset_y;

    private:
        std::vector<Cell*> _the_grid;                                                       //   Array of Cell Objects, representing the grid

        int _num_cells_x;                                                                   //   Number of cells in the grid, on the x axis
        int _num_cells_y;                                                                   //   Number of cells in the grid, on the y axis

        int _width_grid;                                                                    //    Number of pixels for screen width
        int _height_grid;                                                                   //    Number of pixels for screen height

        friend class Controller;
        friend class Renderer;
        friend class Game;

};

#endif