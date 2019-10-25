#include "game.h"
#include "raylib.h"
#include <iostream>

void game::init()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
}

void game::tick()
{
	accumulatedFixedTime += GetFrameTime();

	if (IsMouseButtonPressed(0))
	{
		physObjects.emplace_back();
		std::cout << "Added a physics object!" << std::endl;

		auto& babyPhys = physObjects[physObjects.size() - 1];
		auto mousePos = GetMousePosition();
		babyPhys.pos = { mousePos.x, mousePos.y };
		babyPhys.addForce({ 10000, 0 });
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
