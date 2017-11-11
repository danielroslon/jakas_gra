#include "food.h"


food::food(){}
food::food(Vector2u v): shape(Vector2f(20,20))
{
	float x, y;
	x = (rand() % 40) * 20;
	y = (rand() % 30) * 20;
	position = {x,y};

	shape.setPosition(position);
	shape.setFillColor(Color::Green);
}


food& food::operator=(const food &f)
{
	this->position = f.position;
	this->shape = f.shape;
	return *this;
}

food::~food()
{
}


void food::rysowanie(RenderWindow *w)
{
	w->draw(shape);
}
Vector2f food::getPosition()
{
	return position;
}