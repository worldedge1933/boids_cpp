#pragma once

class Fish
{
	static double speed;
	static double vision;
	static double separation_force;
	static double alignment_force;
	static double cohesion_force;
	static double collision_force;

	double pos_x;
	double pos_y;
	double max_speed;
	double dir_x;
	double dir_y;
	double vel_x;
	double vel_y;
	double acc_x;
	double acc_y;

public:
	Fish(double pos_x, double pos_y, double dir_x, double dir_y);
	Fish(float pos_x, double pos_y);
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
