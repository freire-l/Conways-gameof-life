#ifndef CELL_H
#define CELL_H

#include <random>
#include "SDL.h"


class Cell{
    public:

        Cell(int x, int y, int index);                                              //  Constructor for Cell Class, takes the corresponding
                                                                                    //  x and y coordinated of the cell, and the
                                                                                    //  corresponding index in the grid array


        void handleEvent(int first_x, int first_y, int offset_x, int offset_y);     //  Method that can detect if a the cell has being clicked
                                                                                    //  so it can toggle its life acoordingly


        void toggle_life();                                                          // Method that toggles a Cell between alive and dead

        void set_life(bool value);                                                   // Cell live setter

        bool check_life();                                                           // Cell live getter

        static int _width;                                                          //  Width of the cell class, in pixels
        static int _height;                                                         //  Height of the cell class, in pixels

        int _index;                                                                 //  Corresponding index of the cell object in the Grid array
        

    private:
    SDL_Point _pos;                                                                 //  Position
        bool _is_alive;                                                             //  Variable that holds the life of the cell

        friend class Renderer;
        friend class Grid;
        friend class Controller;

};

#endif