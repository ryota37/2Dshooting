#include <Siv3D.hpp>
#include "Ball.h"
#include "Player.h"
#include "Block.h"

bool isBallHitBlocks(Ball& ball, Block& block)
{
	if (ball.intersects(block))
	{
		return true;
	}
	return false;
}

void Main()
{
	// Initial setting
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	Player player{ Scene::CenterF().x, Scene::Height() * 0.9, 50.0, 50.0, {300.0,0} };
	Array<Ball> balls;
	Array<Block> blocks;
	for (int32 i = 0; i < 4; ++i)
	{
		blocks << Block{ Scene::Width() * i * 0.25, Scene::Height() * 0.25, 180.0, 50.0, false };
	}

	// Main loop
	while (System::Update())
	{
		player.update();
		player.draw();
		player.shoot(balls);

		for (auto& ball : balls)
		{
			ball.update();
			ball.draw();
			ball.vanish();
		}

		for (auto& block : blocks)
		{
			if (!block.getBroken())
			{
				block.draw();
			}
		}

		for (auto& ball : balls)
		{
			for (auto& block : blocks)
			{
				if (isBallHitBlocks(ball, block))
				{
					ball.vanish();
					block.setBroken(true);
				}
			}
		}

		balls.remove_if([](const Ball& ball) { return !ball.isAlive(); });


	//	// Initialize the objects when the game starts
	//	if (KeyEnter.down())
	//	{
	//		ball = { Scene::CenterF().x, Scene::CenterF().y, 20.0,  RandomVec2(500) };
	//		bar = { Scene::CenterF().x, Scene::Height() * 0.9, 200.0, 20.0, {500.0,0} };
	//		for (auto& block : blocks)
	//		{
	//			block.setBroken(false);
	//		}
	//	}

	//	// Rendering and update of the objects
	//	ball.update();
	//	ball.draw();
	//	bar.update();
	//	bar.draw();
	//	for (auto& block : blocks)
	//	{
	//		if (!block.getBroken())
	//		{
	//			block.draw();
	//		}
	//	}

	//	if (ball.intersects(bar))
	//	{
	//		ball.reflect(false, true);
	//	}
	//	for (auto& block : blocks)
	//	{
	//		if (ball.intersects(block) && !block.getBroken())
	//		{
	//			ball.reflect(false, true);
	//			block.setBroken(true);
	//		}
	//	}
	}
}
