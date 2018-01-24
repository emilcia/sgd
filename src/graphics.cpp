#include <SDL2/SDL.h>
#include <stdexcept>
#include <memory>
#include <string>
#include <set>
#include <tuple>
#include <iostream>
#include <thread>
#include <cstdint>
#include <vector>
#include "graphics.hpp"

auto errthrow = []( const std::string &e ) {
	std::string errstr = e + " : " + SDL_GetError();
	SDL_Quit();
	throw std::runtime_error( errstr );
};

std::shared_ptr<SDL_Window> init_window(const int width = 320, const int height = 200) {
	if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) errthrow ( "SDL_Init" );

	SDL_Window *win = SDL_CreateWindow( "Witaj w Swiecie",
										SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
										width, height, SDL_WINDOW_SHOWN );
	if ( win == nullptr ) errthrow ( "SDL_CreateWindow" );
	std::shared_ptr<SDL_Window> window ( win, []( SDL_Window * ptr ) {
		SDL_DestroyWindow( ptr );
	} );
	return window;
}

std::shared_ptr<SDL_Renderer> init_renderer(std::shared_ptr<SDL_Window> window) {
	SDL_Renderer *ren = SDL_CreateRenderer( window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	if ( ren == nullptr ) errthrow ( "SDL_CreateRenderer" );
	std::shared_ptr<SDL_Renderer> renderer ( ren, []( SDL_Renderer * ptr ) {
		SDL_DestroyRenderer( ptr );
	} );
	return renderer;
}
std::shared_ptr<SDL_Texture> load_texture( const std::shared_ptr<SDL_Renderer> renderer, const std::string fname ) {
	SDL_Surface *bmp = SDL_LoadBMP( fname.c_str() );
	if ( bmp == nullptr ) errthrow ( "SDL_LoadBMP" );
	std::shared_ptr<SDL_Surface> bitmap ( bmp, []( SDL_Surface * ptr ) {
		SDL_FreeSurface( ptr );
	} );

	SDL_Texture *tex = SDL_CreateTextureFromSurface( renderer.get(), bitmap.get() );
	if ( tex == nullptr ) errthrow ( "SDL_CreateTextureFromSurface" );
	std::shared_ptr<SDL_Texture> texture ( tex, []( SDL_Texture * ptr ) {
		SDL_DestroyTexture( ptr );
	} );
	return texture;
}
void viewPipes(std::shared_ptr<SDL_Renderer> ren, std::shared_ptr<SDL_Texture> texture, pos_t walls[], pos_t walls2[], pos_t size){
    
        SDL_Point centerPipe = {.x = 35, .y = 60};
        SDL_Rect temp;
    
        for(int i = 0; i < 3; i++ ){
            temp = SDL_Rect {.x = (int) walls[i][0], .y = (int) walls[i][1], .w = (int) size[0], .h = (int) size[1]};
            SDL_RenderCopy( ren.get(), texture.get(), NULL, &temp );
            temp = SDL_Rect {.x = (int) walls2[i][0], .y = (int) walls2[i][1], .w = (int) size[0], .h = (int) size[1]};		
            SDL_RenderCopyEx( ren.get(), texture.get(), NULL, &temp, 180, &centerPipe, SDL_FLIP_HORIZONTAL );			
        }	
    }
void drawBird(std::shared_ptr<SDL_Renderer> ren, std::shared_ptr<SDL_Texture> bird_texture, pos_t &bird_pos){
    SDL_Point center = {.x = 32, .y = 32};
    SDL_Rect dstrect = {.x = ( int )( bird_pos[0] ), .y = ( int )( bird_pos[1]  ), .w = 64, .h = 64};
    SDL_RenderCopyEx( ren.get(), bird_texture.get(), NULL, &dstrect, 5, &center, SDL_FLIP_NONE );
}