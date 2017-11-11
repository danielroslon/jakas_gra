#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;


class snake
{
private:
	RectangleShape kreska;
	char kierunek;
public:
	snake(Vector2u);
	~snake();

	void ruch(Event*);
	void zmiana_kierunku(Event*);

	friend class gra;
};

