#include <iostream>
#include "SDL.h"
#include "cell.h"

//****************************************************//
//*****         Cell Class Constructor          ******//
//****************************************************//

Cell::Cell(int x, int y, int index){
    _pos.x = x;         //x coordinate
    _pos.y = y;         //y coordinate

    _is_alive = false;  //cell is created dead

    _index = index;     //corresponding index in the grid array
}

void Cell::set_life(bool value){ _is_alive = value;}
bool Cell::check_life(){return _is_alive;}

int Cell::get_x(){return _pos.x;}
int Cell::get_y(){return _pos.y;}

//****************************************************//
//*****           Handle event Method           ******//
//****************************************************//
void Cell::handleEvent(int first_x, int first_y, int offset_x, int offset_y){

        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );

        //Get Current most upper left pixel of the Cell
        int cell_x=(((_pos.x)-first_x)*(_width))+offset_x;
        int cell_y=(((_pos.y)-first_y)*(_height))+offset_y;

        //Variable to check if the click was made inside the cell
        bool inside = true;

        //Mouse is left of the cell
        if( x < cell_x )
        {
            inside = false;
        }
        //Mouse is right of the cell
        else if( x > cell_x+ _width)
        {
            inside = false;
        }
        //Mouse above the cell
        else if( y < cell_y )
        {
            inside = false;
        }
        //Mouse below the cell
        else if( y > cell_y + _height)
        {
            inside = false;
        }

        //Mouse is outside the cell
        if( !inside ){}
        //Mouse is inside button
        else{
                toggle_life();
        }
}

//****************************************************//
//*****           Toggle life Method            ******//
//****************************************************//
void Cell::toggle_life(){
    if (_is_alive == false)
    {
        _is_alive = true;              //If it is dead, make it alive
    }
    else if (_is_alive == true)
    {
        _is_alive = false;             //If it is alive, make it dead
    }
}

