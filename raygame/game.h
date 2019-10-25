#pragma once

#include <vector>

#include "physics.h"

class game
{
	float accumulatedFixedTime = 0;

	std::vector<physObject> physObjects;

public:
	void init();
	void tick();
	void tickPhys();
	void draw() const;
	void exit();

	bool shouldClose() const;
	bool shouldPhysics() const;

	float targetFixedStep = 0;
};