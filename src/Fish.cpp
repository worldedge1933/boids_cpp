#include <cmath>
#include "Fish.hpp"


float Fish::speed = 4;
float Fish::vision = 100;
float Fish::separation_force = 5;
float Fish::alignment_force = 5;
float Fish::cohesion_force = 0.3;
float Fish::collision_force = 25;

Fish::Fish(float pos_x, float pos_y, float dir_x, float dir_y) {

    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->max_speed = speed;
    this->dir_x = dir_x;
    this->dir_y = dir_y;

    this->vel_x = speed * dir_x / (sqrt(dir_x * dir_x + dir_y * dir_y));
    this->vel_y = speed * dir_y / (sqrt(dir_x * dir_x + dir_y * dir_y));



}