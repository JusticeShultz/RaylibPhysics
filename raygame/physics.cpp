#include "physics.h"
#include "raylib.h"

void physObject::addForce(glm::vec2 force)
{
	forces += force * 1.0f / mass;
}

void physObject::addImpulse(glm::vec2 impulse)
{
	vel += impulse * (1.0f / mass);
}

void physObject::addAccel(glm::vec2 accel)
{
	vel += accel;
}

void physObject::addVelocityChange(glm::vec2 delta)
{
	vel += delta;
}

void physObject::tickPhys(float delta)
{
	vel += forces * delta;
	forces = { 0, 0 };

	vel *= 1.0f - delta * drag;
	pos += vel * delta;

	if (pos.x < -10) pos.x = GetScreenWidth();
	else if (pos.x > GetScreenWidth() + 10) pos.x = 0;

	if (pos.y < -10) pos.y = GetScreenHeight();
	else if (pos.y > GetScreenHeight() + 10) pos.y = 0;
}

void physObject::draw() const
{
	if(isCircle)
		DrawCircleLines(pos.x, pos.y, 15.0f, RED);
	else DrawRectangleLines(pos.x, pos.y, 15.0f, 15.0f, RED);
}