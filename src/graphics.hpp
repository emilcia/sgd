#ifndef __GRAPHICS_H__
#define  __GRAPHICS_H__
#include "physics.hpp"

std::shared_ptr<SDL_Window> init_window( int width , int height );
std::shared_ptr<SDL_Renderer> init_renderer( std::shared_ptr<SDL_Window> window );
std::shared_ptr<SDL_Texture> load_texture( const std::shared_ptr<SDL_Renderer> renderer, const std::string fname );
void viewPipes(std::shared_ptr<SDL_Renderer> ren, std::shared_ptr<SDL_Texture> texture, pos_t walls[], pos_t walls2[], pos_t size);
void drawBird(std::shared_ptr<SDL_Renderer> ren, std::shared_ptr<SDL_Texture> bird_texture, pos_t &bird_pos);
    
#endif