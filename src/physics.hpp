#ifndef __PHYSICS_H__
#define __PHYSICS_H__

using pos_t = std::array<double, 2>;

void calculate_acceleration(pos_t &birdV, bool &game_started);
void moveWalls(pos_t walls[], pos_t walls2[], double time, pos_t v, int &points);
bool detect_collision_with_wall(pos_t wall, pos_t size, double x, double y);
void collision(pos_t walls[], pos_t bird_pos, pos_t size, bool &game_active, pos_t walls2[]);
void birdPosition(pos_t &bird_pos, pos_t &bird_v, pos_t bird_a, double dt);
    
#endif
    
    
