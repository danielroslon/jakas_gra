#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class gra
{
private:
	RenderWindow okno;
	Vector2i resolution;
	bool fullscreen;
public:
	gra(int,int,bool);
	~gra();

	void start();

};

