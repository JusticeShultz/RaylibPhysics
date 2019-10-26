#pragma once

#include "glm/glm.hpp"
#include "shapes.h"

class physObject
{
public:
	glm::vec2 pos;
	glm::vec2 vel;

	glm::vec2 forces;

	float mass;
	float drag;

	shape collider;

	void tickPhys(float delta);
	void draw() const;

	void addForce(glm::vec2 force);
	void addImpulse(glm::vec2 impulse);
	void addAccel(glm::vec2 accel);
	void addVelocityChange(glm::vec2 delta);

	bool isCircle = false;

	physObject() 
	{
		pos = { 0,0 };
		vel = { 0,0 };
		forces = { 0,0 };

		mass = 1.0f;
		drag = 1.0f;
	}
};