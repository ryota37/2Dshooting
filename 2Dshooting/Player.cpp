#include <Siv3D.hpp>
#include "Player.h"
#include "Ball.h"

Player::Player(double x, double y, double w, double h, Vec2 initialVelocity)
	:RectF(x, y, w, h), velocity(initialVelocity)
{

}

void Player::update()
{
	if (KeyLeft.pressed())
	{
		x = Max((x - velocity.x * Scene::DeltaTime()), 0.0);
	}
	if (KeyRight.pressed())
	{
		x = Min((x + velocity.x * Scene::DeltaTime()), Scene::Width() * 1.0 - 50.0);
	}
}

void Player::shoot(Array<Ball>& balls)
{
	if (KeyEnter.down())
	{
		balls << Ball{ x, y, 20.0,  {0,-100} };
	}
	// Add new ball to balls array when EnterKey pressed.
	// the ball will be deleted when it hits block or wall
}
