#ifndef BALL_H
#define BALL_H

#include <Siv3D.hpp>

class Ball : public Circle
{
private:
	Vec2 velocity;
	bool isCollided;
	bool alive;

public:
	Ball(double x, double y, double r, Vec2 initialVelocity, bool isAlive);

	void setVelocity(Vec2 newVelocity);
	Vec2 getVelocity();

	void update();
	void vanish();
	bool isBallintersectsWall();
	bool isAlive() const;
};

#endif // BALL_H
