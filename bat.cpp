#include "bat.h"

Bat::Bat(double pos_x, double pos_y)
{

	this->position.x = pos_x;
	this->position.y = pos_y;
	shape.setPosition(position);
	shape.setSize(Vector2f(3, 50));
}
RectangleShape Bat::m_getShape()
{
	return shape;
}
FloatRect Bat::m_getPosition()
{
	return shape.getGlobalBounds();
}
void Bat::Move(double y)
{
	this->position.y += y;
	if (this->position.y >= 595 || this->position.y <= 0)
	{
		this->position.y -= y;
	}
	shape.setPosition(position);
}