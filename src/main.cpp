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

void calculate_acceleration(pos_t &birdV, bool &game_started){

	//birdA = {0,25};
		
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_SPACE]) {
		birdV = {0, -70};
		game_started=true;
	}
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
void moveWalls(pos_t walls[], pos_t walls2[], double time, pos_t v){

	for(int i=0; i<3; i++){
		walls[i][0] = walls[i][0] + (int)(v[0] * time);	
		walls2[i][0] = walls[i][0] + (int)(v[0] * time);	
		if(walls[i][0]<-70 && walls2[i][0]<-70){
			walls[i][0] = 640;
			walls2[i][0] = 640;		
		}
	}
}
bool detect_collision_with_wall(pos_t wall, pos_t size, double x, double y){
	return ((x+64 > wall[0]) 
		&& (x < wall[0] + size[0]) 
		&& (y + 64 > wall[1]+30)
		&& (y < wall[1] + size[1]));
}

void collision(pos_t walls[], pos_t bird_pos, pos_t size, bool &game_active, pos_t walls2[]){

	//std::cout << bird_pos[1] << std::endl;
	if(bird_pos[1]>480 || bird_pos[1]<0){
		game_active = false;
	}
	
	for( int i = 0; i < 3; i++ ){	
		if(detect_collision_with_wall(walls[i], size, bird_pos[0], bird_pos[1])
		|| detect_collision_with_wall(walls2[i], size, bird_pos[0], bird_pos[1])){
			game_active = false;
		}
	}
}


int main( ) { // int argc, char **argv ) {	
	auto window = init_window(640,480);
	auto renderer = init_renderer(window);
	auto bird_texture = load_texture( renderer, "texture/koliber.bmp" );
	auto pipe_texture = load_texture( renderer, "texture/pipe.bmp" );	

	bool game_started = false;
	pos_t bird_pos = {2, 240};
	pos_t pipe_v = {-100, 0};
	pos_t bird_v = {0, 0};
	pos_t bird_a = {0, 150};
	pos_t pipe_size = {70, 120};
	double dt = 1 / 30.0;
	auto current_time = std::chrono::system_clock::now();
	auto new_time = current_time;
	pos_t pipe1 = {50, 360};
	pos_t pipe2 = {250, 360};	
	pos_t pipe3 = {500, 360};
	pos_t walls[] = {pipe1,pipe2,pipe3};	
	pipe1[1]=0;
	pipe2[1]=0;
	pipe3[1]=0;
	pos_t walls2[] = {pipe1,pipe2,pipe3};	

	for ( bool game_active = true ; game_active; ) {
		SDL_Event event;
		while ( SDL_PollEvent( &event ) ) {
			if ( event.type == SDL_QUIT ) game_active = false;
		}

		SDL_RenderClear( renderer.get() );
		SDL_Point center = {.x = 32, .y = 32};
		SDL_Rect dstrect = {.x = ( int )( bird_pos[0] ), .y = ( int )( bird_pos[1]  ), .w = 64, .h = 64};
		SDL_RenderCopyEx( renderer.get(), bird_texture.get(), NULL, &dstrect, 5, &center, SDL_FLIP_NONE );
		viewPipes( renderer, pipe_texture, walls, walls2, pipe_size);
		calculate_acceleration(bird_v, game_started);		

		if(game_started){
			bird_pos = bird_pos + bird_v * dt + bird_v * bird_a * 0.5 * dt * dt;
			bird_v = bird_v + bird_a * dt;
			collision(walls, bird_pos, pipe_size, game_active, walls2);
			moveWalls(walls, walls2, dt, pipe_v);			
		}
		
		new_time = current_time + std::chrono::milliseconds((int)(1000.0*dt));
		std::this_thread::sleep_until (new_time);
		current_time = new_time;
		SDL_RenderPresent( renderer.get() );
	}
	return 0;
}
