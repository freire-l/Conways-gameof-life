#ifndef CELL_H
#define CELL_H

#include <random>
#include "SDL.h"
//#include "controller.h"
//#include "renderer.h"

//const int CELL_WIDTH = 100;
//const int CELL_HEIGHT = 100;

class Cell{
    public:
        //Cell(int x, int y, int w, int h);
        Cell(int x, int y, int index);
        void setter_Pos(int x, int y);
        void handleEvent(SDL_Event* e, int first_x, int first_y, int offset_x, int offset_y);

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
        //position
        SDL_Point _pos;
        bool _is_alive;
        bool _to_update;
        //bool _next_life;
        //int _width;
        //int _height;

        friend class Renderer;
        friend class Grid;
        friend class Controller;

        

};

#endif