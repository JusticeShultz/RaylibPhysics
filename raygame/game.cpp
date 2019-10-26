#include "game.h"
#include "raylib.h"
#include <iostream>

void game::init()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1920 * 0.9f;
	int screenHeight = 1080 * 0.9f;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
}

void game::tick()
{
	accumulatedFixedTime += GetFrameTime();

	bool mb0 = IsMouseButtonPressed(0);
	bool mb1 = IsMouseButtonPressed(1);

	if (mb0 || mb1)
	{
		physObjects.emplace_back();
		std::cout << "Added a physics object!" << std::endl;

		auto& babyPhys = physObjects[physObjects.size() - 1];
		auto mousePos = GetMousePosition();
		babyPhys.pos = { mousePos.x, mousePos.y };

		babyPhys.addForce({ 25000, GetRandomValue(-20000, 20000) });

		if (mb0)
		{
			babyPhys.isCircle = true;
			babyPhys.collider = circle{ 15.0f };
		}
		else
		{
			babyPhys.isCircle = false;
			babyPhys.collider = aabb{ {15, 15} };
		}
	}
}

void game::tickPhys()
{
	accumulatedFixedTime -= targetFixedStep;

	//std::cout << "PHYS TICK" << std::endl;
	for (auto& i : physObjects)
	{
		i.tickPhys(targetFixedStep);
	}

	for (auto &i : physObjects)
	{
		for (auto &j : physObjects)
		{
			if (&i == &j) continue;

			bool collision = false;

			i.collider.match([i, j, &collision](circle c) { if (checkCircleX(i.pos, c, j.pos, j.collider)) { collision = true; } },
							 [i, j, &collision](aabb a) { if (checkAABBX(i.pos, a, j.pos, j.collider))	   { collision = true; }});

			if (collision) {
				resolvePhysBodies(i, j);
			}
		}
	}
}

void game::draw() const
{
	// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
	BeginDrawing();

	ClearBackground(RAYWHITE);

	//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	for (const auto& i : physObjects)
	{
		i.draw();
	}

	EndDrawing();
	//----------------------------------------------------------------------------------
}

void game::exit()
{
	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
}

bool game::shouldClose() const
{
	return WindowShouldClose();
}

bool game::shouldPhysics() const
{
	return accumulatedFixedTime >= targetFixedStep;
}
