#include <iostream>
#include "SDL.h"
#include "cell.h"


        /*Cell::Cell(int x, int y, int w, int h){
            _pos.x = x;
            _pos.y = y;
            _width = w;
            _height = h;

            _is_alive = false;
        }*/

        Cell::Cell(int x, int y, int index){
            _pos.x = x;
            _pos.y = y;

            /*
            if((x==y)||((x+y)==15))
            _is_alive = true;
            else
            */
            _is_alive = false;

            _index = index;

            //_next_life = false;
        }

        void Cell::setter_Pos(int x, int y){
            _pos.x = x;
            _pos.y = y;

        }

        void Cell::set_life(bool value){ _is_alive = value;}
        bool Cell::check_life(){return _is_alive;}

        int Cell::get_x(){return _pos.x;}
        int Cell::get_y(){return _pos.y;}

        void Cell::handleEvent(SDL_Event* e, int first_x, int first_y, int offset_x, int offset_y){
            //If mouse event happened
            if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
            {
                //Get mouse position
                int x, y;
                SDL_GetMouseState( &x, &y );
                int cell_x=(((_pos.x)-first_x)*(_width))+offset_x;
                int cell_y=(((_pos.y)-first_y)*(_height))+offset_y;

                //Check if mouse is in button
                bool inside = true;

                //Mouse is left of the button
                if( x < cell_x )
                {
                    inside = false;
                }
                //Mouse is right of the button
                else if( x > cell_x+ _width)
                {
                    inside = false;
                }
                //Mouse above the button
                else if( y < cell_y )
                {
                    inside = false;
                }
                //Mouse below the button
                else if( y > cell_y + _height)
                {
                    inside = false;
                }

                //Mouse is outside button
                if( !inside )
                {
                    //std::cout<<"afuera"<<std::endl;
                }
                //Mouse is inside button
                else
                {
                    //Set mouse over sprite
                    switch( e->type )
                    {
                        case SDL_MOUSEMOTION:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                        break;
                    
                        case SDL_MOUSEBUTTONDOWN:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                        std::cout<<"centro click "<< "x: " <<_pos.x<<"  y: "<<_pos.y <<std::endl;
                        toggle_life();
                        break;
                        
                        case SDL_MOUSEBUTTONUP:
                        //mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                        break;
                    }
                }
            }
        }

        void Cell::toggle_life(){
            //std::cout<<"yay"<<std::endl;
            if (_is_alive == false)
            {
                _is_alive = true;
                //std::cout<<"oe"<<std::endl;

            }
            else if (_is_alive == true)
            {
                _is_alive = false;
                //std::cout<<"flaco"<<std::endl;

            }
        }

        //Cell::void render();

