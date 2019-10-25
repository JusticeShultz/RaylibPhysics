#include "physics.h"
#include "raylib.h"

void physObject::addForce(glm::vec2 force)
{
	forces += force * 1.0f / mass;
}

void physObject::tickPhys(float delta)
{
	vel += forces * delta;
	forces = { 0, 0 };

	vel *= 1.0f - delta * drag;
	pos += vel * delta;
}

void physObject::draw() const
{
	DrawCircleLines(pos.x, pos.y, 15.0f, RED);
}