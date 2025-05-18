#include <Siv3D.hpp>
#include "Ball.h"

Ball::Ball(double x, double y, double r, Vec2 initialVelocity)
	: Circle(x, y, r), velocity(initialVelocity)
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
