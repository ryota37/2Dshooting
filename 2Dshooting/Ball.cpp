#include <Siv3D.hpp>
#include "Ball.h"

Ball::Ball(double x, double y, double r, Vec2 initialVelocity, bool initialAlive)
	: Circle(x, y, r), velocity(initialVelocity), alive(initialAlive)
{

}

void Ball::setVelocity(Vec2 newVelocity)
{
	velocity = newVelocity;
}
Vec2 Ball::getVelocity()
{
	return velocity;
}

void Ball::update()
{
	x += (velocity.x * Scene::DeltaTime());
	y += (velocity.y * Scene::DeltaTime());
}

bool Ball::isBallintersectsWall()
{
	// Collision detection of balls
	if (x <= 0 || (Scene::Width() <= x))
	{
		return true;
	}
	if (y <= 0 || Scene::Height() <= y)
	{
		return true;
	}
	return false;
}

bool Ball::isAlive() const
{
	if (alive) return true;
	return false;
}

void Ball::vanish()
{
	if (isBallintersectsWall())
	{
		alive = false;
	}
}
