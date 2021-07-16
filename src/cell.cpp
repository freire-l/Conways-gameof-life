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

        Cell::Cell(int x, int y){
            _pos.x = x;
            _pos.y = y;

            _is_alive = false;
        }

        void Cell::setter_Pos(int x, int y){
            _pos.x = x;
            _pos.y = y;

        }
        void Cell::handleEvent(SDL_Event* e){
            //If mouse event happened
            if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
            {
                //Get mouse position
                int x, y;
                SDL_GetMouseState( &x, &y );

                //Check if mouse is in button
                bool inside = true;

                //Mouse is left of the button
                if( x < _pos.x )
                {
                    inside = false;
                }
                //Mouse is right of the button
                else if( x > _pos.x + _width)
                {
                    inside = false;
                }
                //Mouse above the button
                else if( y < _pos.y )
                {
                    inside = false;
                }
                //Mouse below the button
                else if( y > _pos.y + _height)
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
                        std::cout<<"centro click"<<std::endl;
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

