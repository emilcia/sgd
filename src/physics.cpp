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
#include "physics.hpp"

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
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_SPACE]) {
        birdV = {0, -70};
        game_started=true;
    }
}

void moveWalls(pos_t walls[], pos_t walls2[], double time, pos_t v, int &points){

    for(int i=0; i<3; i++){
        walls[i][0] = walls[i][0] + (int)(v[0] * time);	
        walls2[i][0] = walls[i][0] + (int)(v[0] * time);	
        if(walls[i][0]<-70 && walls2[i][0]<-70){
            walls[i][0] = 640;
            walls2[i][0] = 640;		
            points++;
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

void birdPosition(pos_t &bird_pos, pos_t &bird_v, pos_t bird_a, double dt){
    bird_pos = bird_pos + bird_v * dt + bird_v * bird_a * 0.5 * dt * dt;
    bird_v = bird_v + bird_a * dt;
}