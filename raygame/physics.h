#pragma once
#include "glm/glm.hpp"

class physObject
{
public:
	glm::vec2 pos;
	glm::vec2 vel;

	glm::vec2 forces;

	float mass;
	float drag;

	void tickPhys(float delta);
	void draw() const;

	void addForce(glm::vec2 force);

	physObject() 
	{
		pos = { 0,0 };
		vel = { 0,0 };
		forces = { 0,0 };

		mass = 1.0f;
		drag = 1.0f;
	}
};