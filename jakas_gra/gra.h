#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <Windows.h>

#include "snake.h"

using namespace sf;

class gra
{
private:
	RenderWindow window;
	snake s;
public:
	gra();
	~gra();


	void loop();
};

