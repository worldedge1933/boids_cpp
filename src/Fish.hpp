#pragma once

class Fish
{
	static float speed;
	static float vision;
	static float separation_force;
	static float alignment_force;
	static float cohesion_force;
	static float collision_force;

	float pos_x;
	float pos_y;
	float max_speed;
	float dir_x;
	float dir_y;
	float vel_x;
	float vel_y;
	float acc_x;
	float acc_y;

public:
	Fish(float pos_x, float pos_y, float dir_x, float dir_y);
	Fish(float pos_x, float pos_y);
    Fish();
	~Fish();
	void update();
	void setSpeed(float s);
	void setSeparationForce(float s);
	void setAlignmentForce(float s);
	void setCohesionForce(float s);
	void setCollisionForce(float s);
	float getSpeed();
	float getSeparationForce();
	float getAlignmentForce();
	float getCohesionForce();
	float getCollisionForce();
};
