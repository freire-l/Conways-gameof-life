#ifndef CELL_H
#define CELL_H

#include <random>
#include "SDL.h"


class Cell{
    public:
        /*
            Constructor for Cell Class, takes the corresponding x and y coordinated of the cell, and the
            corresponding index in the grid array
        */
        Cell(int x, int y, int index);

        /*
            Method that can detect if a the cell has being clicked, so it can toggle its life acoordingly
        */
        void handleEvent(int first_x, int first_y, int offset_x, int offset_y);

        /*
            Method that toggles a Cell between alive and dead
        */
        void toggle_life();

        void set_life(bool value);
        bool check_life();

        int get_x();
        int get_y();

        void render();

        static int _width;
        static int _height;

        int _index;
        

    private:
        SDL_Point _pos;        //position
        bool _is_alive;

        friend class Renderer;
        friend class Grid;
        friend class Controller;

};

#endif