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

int main( ) { // int argc, char **argv ) {	
	auto window = init_window(640,480);
	auto renderer = init_renderer(window);
	auto bird_texture = load_texture( renderer, "texture/koliber.bmp" );
	auto pipe_texture = load_texture( renderer, "texture/pipe.bmp" );	

	bool game_started = false;
	int points = 0;
	pos_t bird_pos = {2, 240};
	pos_t pipe_v = {-100, 0};
	pos_t bird_v = {0, 0};
	pos_t bird_a = {0, 180};
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
		drawBird( renderer, bird_texture, bird_pos);
		viewPipes( renderer, pipe_texture, walls, walls2, pipe_size);
		calculate_acceleration(bird_v, game_started);		

		if(game_started){
			birdPosition(bird_pos, bird_v, bird_a, dt);
			collision(walls, bird_pos, pipe_size, game_active, walls2);
			moveWalls(walls, walls2, dt, pipe_v, points);			
		}
		
		new_time = current_time + std::chrono::milliseconds((int)(1000.0*dt));
		std::this_thread::sleep_until (new_time);
		current_time = new_time;
		SDL_RenderPresent( renderer.get() );
	}
	std::cout << "Twoj wynik: " << points << std::endl;
	return 0;
}
