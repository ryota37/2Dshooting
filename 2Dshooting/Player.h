#include <Siv3D.hpp>
#include "Ball.h"

class Player : public RectF
{
private:
	Vec2 velocity;
public:
	Player(double x, double y, double w, double h, Vec2 initialVelocity);
	void update();
	void shoot(Array<Ball>& balls);
};
