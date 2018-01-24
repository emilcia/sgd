/**
 * This is the simple hello world for SDL2.
 *
 * The example tries to take care of resource allocation and deallocation
 * using smart pointers.
 */

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

using pos_t = std::array<double, 2>;

pos_t operator +( const pos_t &a, const pos_t &b ) {
	return {a[0] + b[0], a[1] + b[1]};
}
pos_t operator -( const pos_t &a, const pos_t &b ) {
	return {a[0] - b[0], a[1] - b[1]};
}
pos_t operator *( const pos_t &a, const pos_t &b ) {
	return {a[0]*b[0], a[1]*b[1]};
}
pos_t operator *( const pos_t &a, const double &b ) {
	return {a[0]*b, a[1]*b};
}

void calculate_acceleration(pos_t &birdV){

	//birdA = {0,25};
		
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_SPACE]) {
		birdV = {0, -20};
	}
}

void viewPipes(std::shared_ptr<SDL_Renderer> ren, std::shared_ptr<SDL_Texture> texture, SDL_Rect walls[], SDL_Rect walls2[]){

	SDL_Point centerPipe = {.x = 60, .y = 100};

	for(int i = 0; i < 3; i++ ){
		SDL_RenderCopyEx( ren.get(), texture.get(), NULL, &walls[i], 0, &centerPipe, SDL_FLIP_NONE );	
		SDL_RenderCopyEx( ren.get(), texture.get(), NULL, &walls2[i], 180, &centerPipe, SDL_FLIP_HORIZONTAL );			
	}	
}
void moveWalls(SDL_Rect walls[], SDL_Rect walls2[], double time, pos_t v){

	pos_t wall_pos;
	for(int i=0; i<3; i++){
		//walls[i].x = walls[i].x + v[0] * time;
		wall_pos = {walls[i].x, walls[i].y};
		wall_pos = wall_pos + v*time;
		walls[i].x = wall_pos[0];		
		std::cout << walls[i].x << std::endl;  		
	}
}


int main( ) { // int argc, char **argv ) {	
	auto window = init_window(640,480);
	auto renderer = init_renderer(window);
	auto bird_texture = load_texture( renderer, "texture/koliber.bmp" );
	auto pipe_texture = load_texture( renderer, "texture/pipe.bmp" );	

	pos_t bird_pos = {2, 20};
	pos_t pipe_v = {-10, 0};
	pos_t bird_v = {0, 10};
	pos_t bird_a = {0, 25};
	double scale = 5;
	double dt = 1 / 30.0;
	auto current_time = std::chrono::system_clock::now();
	auto new_time = current_time;
	SDL_Rect pipe1 = {.x = 50, .y = 280, .w = 120, .h = 200};
	SDL_Rect pipe2 = {.x = 250, .y = 280, .w = 120, .h = 200};	
	SDL_Rect pipe3 = {.x = 500, .y = 280, .w = 120, .h = 200};
	SDL_Rect walls[] = {pipe1,pipe2,pipe3};	
	pipe1.y=0;
	pipe2.y=0;
	pipe3.y=0;
	SDL_Rect walls2[] = {pipe1,pipe2,pipe3};	

	for ( bool game_active = true ; game_active; ) {
		SDL_Event event;
		while ( SDL_PollEvent( &event ) ) {
			if ( event.type == SDL_QUIT ) game_active = false;
		}

		bird_pos = bird_pos + bird_v * dt + bird_v * bird_a * 0.5 * dt * dt;
		bird_v = bird_v + bird_a * dt;
		moveWalls(walls, walls2, dt, pipe_v);
		
		SDL_RenderClear( renderer.get() );
		SDL_Point center = {.x = 32, .y = 32};
		SDL_Rect dstrect = {.x = ( int )( bird_pos[0] * scale ), .y = ( int )( bird_pos[1] * scale ), .w = 64, .h = 64};
		SDL_RenderCopyEx( renderer.get(), bird_texture.get(), NULL, &dstrect, 5, &center, SDL_FLIP_NONE );
		viewPipes( renderer, pipe_texture, walls, walls2);

		calculate_acceleration(bird_v);
		
		new_time = current_time + std::chrono::milliseconds((int)(1000.0*dt));
		std::this_thread::sleep_until (new_time);
		current_time = new_time;
		SDL_RenderPresent( renderer.get() );
	}
	return 0;
}
