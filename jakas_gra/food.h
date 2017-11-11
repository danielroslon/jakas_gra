#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <string>

using namespace sf;

class food
{
private:
	RectangleShape shape;
	Vector2f position;
public:
	food();
	food(Vector2u);
	~food();

	food& operator=(const food&);
	Vector2f getPosition();

	void rysowanie(RenderWindow*);


};

